using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;


namespace WindowsFormsApp1
{
    public class Container
    {
        public string Name { get; set; }
        public int Weight { get; set; }
        public Tuple<int, int> Pos { get; set; }
        public int Status { get; set; }
    }

    public static class ManifestManager
    {
        public static int CheckName(string name)
        {
            if (name == "NAN") return -1;
            if (name == "UNUSED") return 0;
            return 2;
        }

        public static List<List<Container>> ReadManifest(string filePath)
        {
            var ship = new List<List<Container>>();
						
			using (var manifest = new StreamReader(filePath))
            {
                string line;
                int currentRow = -1;
				List<Container> rowOfContainers = new List<Container>();
                while ((line = manifest.ReadLine()) != null)
                {
                    var Part = line.Substring(0, line.LastIndexOf('}') + 1);
                    var namePart = line.Substring(line.LastIndexOf('}') + 1).Trim();
                    namePart = namePart.Substring(2);

                    var parts = Part.Split(new[] { '[', ']', ',', '{', '}', ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int row = int.Parse(parts[0]);
                    int col = int.Parse(parts[1]);
                    int weight = int.Parse(parts[2]);

                    var container = new Container
                    {
                        Pos = Tuple.Create(row, col),
                        Weight = weight,
                        Name = namePart,
                        Status = CheckName(namePart)
                    };


                    // Add container to the corresponding row
                    if (row != currentRow)
                    {
                        if (currentRow != -1)
                        {
                            ship.Add(new List<Container>(rowOfContainers));
                            rowOfContainers.Clear();
                        }
                        currentRow = row;
                    }
                    rowOfContainers.Add(container);
                }

                // Add the last row if it's not empty
                if (rowOfContainers.Count > 0)
                {
                    ship.Add(rowOfContainers);
                }
			}

			List<Container> firstRow = new List<Container>();
			for (int i = 0; i < 12; i++)
			{
				Container cont = new Container
				{
					Pos = Tuple.Create(0, 0),
					Weight = 0,
					Name = "UNUSED",
					Status = 0
				};
				firstRow.Add(cont);
			}
			ship.Add(firstRow);

			ship.Reverse();
            return ship;
        }

        public static void UpdateManifest(List<List<Container>> bigShip, string path)
        {
			List<List<Container>> ship = new List<List<Container>>();
			for(int i = 1; i < bigShip.Count; i++)
			{
				ship.Add(bigShip[i]);
			}
			ship.Reverse();

            using (var file = new StreamWriter(path))
            {
				for (int row = 0; row < ship.Count; row++)
				{
					for (int col = 0; col < ship[0].Count; col++)
					{
						//file.WriteLine($"[{container.Pos.Item1},{container.Pos.Item2}], {{{container.Weight}}}, {container.Name}");
						string formattedLine = $"[{(row+1):D2},{(col+1):D2}], {{{ship[row][col].Weight.ToString("D5")}}}, {Program.shipNames[row][col]}";
						file.WriteLine(formattedLine);
					}
				}
            }

            string newPath = Path.Combine(Path.GetDirectoryName(path), Path.GetFileNameWithoutExtension(path) + "OUTBOUND" + Path.GetExtension(path));
            File.Move(path, newPath);
        }

        public static void Print(List<List<Container>> ship)
        {
            for (int i = ship.Count - 1; i >= 0; i--)
            {
                foreach (var container in ship[i])
                {
                    Console.Write($"{CheckName(container.Name)} ");
                }
                Console.WriteLine();
            }
        }
    }

    public static class LoadedContainerManager
    {
        public static Container SetLoadedContainerInfo(string name)
        {
            Container container = new Container();
            container.Name = name;
            container.Weight = 0;
            container.Status = 2;
            return container;
        }

        public static void RemoveContainerNameFromRemoveList(string name)
        {
            for (int i = 0; i < Program.removeList.Count; i++)
            {
                if (Program.removeList[i] == name)
                {
                    Program.removeList.RemoveAt(i);
                    break;
                }
            }
        }

        public static void AddContainerNameToRemoveList(string name)
        {
            Program.removeList.Add(name);
        }
    }

    public static class LogManager
    {
        public static string GetCurrentTime()
        {
            DateTime now = DateTime.Now;
            int day = now.Day;
            string suffix;

            if (day == 1 || day == 21 || day == 31)
                suffix = "st";
            else if (day == 2 || day == 22)
                suffix = "nd";
            else if (day == 3 || day == 23)
                suffix = "rd";
            else
                suffix = "th";

            // Adjusted format string for proper date and time formatting
            return now.ToString($"MMMM d'{suffix}' yyyy: HH:mm");
        }
		
        public static void AddNoteToLogFile(string input)
        {
			string filePath = Helper.getPathToLog();
			CheckOrCreateFile(filePath);
            string note = GetCurrentTime() + " " + input;
            File.AppendAllText(filePath, note + Environment.NewLine);
        }

        public static void CheckOrCreateFile(string filePath)
        {
            // Check if the file exists
            if (!File.Exists(filePath))
            {
                // Create the file
                FileStream fs = File.Create(filePath);
				fs.Close();
                Console.WriteLine($"File created: {filePath}");
            }
            else
            {
                Console.WriteLine($"File already exists: {filePath}");
            }
        }
    }
}
