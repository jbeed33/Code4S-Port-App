using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;


namespace ConsoleApp1
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
            return ship;
        }

        public static void UpdateManifest(List<List<Container>> ship, string path)
        {
            using (var file = new StreamWriter(path))
            {
                foreach (var row in ship)
                {
                    foreach (var container in row)
                    {
                        //file.WriteLine($"[{container.Pos.Item1},{container.Pos.Item2}], {{{container.Weight}}}, {container.Name}");
                        string formattedLine = $"[{container.Pos.Item1:D2},{container.Pos.Item2:D2}], {{{container.Weight:D4}}}, {container.Name}";
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

        public static List<string> removeList = new List<string>();

        public static void RemoveContainerNameFromRemoveList(string name)
        {
            for (int i = 0; i < removeList.Count; i++)
            {
                if (removeList[i] == name)
                {
                    removeList.RemoveAt(i);
                    break;
                }
            }
        }

        public static void AddContainerNameToRemoveList(string name)
        {
            removeList.Add(name);
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

        public static void AddNoteToLogFile(string filePath, string input)
        {
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
                Console.WriteLine($"File created: {filePath}");
            }
            else
            {
                Console.WriteLine($"File already exists: {filePath}");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Container myContainer = LoadedContainerManager.SetLoadedContainerInfo("Sample Container");

            Console.WriteLine("Container Details:");
            Console.WriteLine($"Name: {myContainer.Name}");
            Console.WriteLine($"Weight: {myContainer.Weight}");
            Console.WriteLine($"Status: {myContainer.Status}");

            LoadedContainerManager.AddContainerNameToRemoveList("Container1");
            LoadedContainerManager.AddContainerNameToRemoveList("Container2");
            LoadedContainerManager.AddContainerNameToRemoveList("Container3");
            LoadedContainerManager.RemoveContainerNameFromRemoveList("Container1");

            Console.WriteLine("Containers in Remove List:");
            foreach (string name in LoadedContainerManager.removeList)
            {
                Console.WriteLine(name);
            }

            // Define a file path for the log file
            // Ensure this path is accessible and writable in your environment
            string logFilePath = @"C:\Users\zhika\OneDrive\Desktop\cs179\readManifest\log.txt"; // Change this path as needed

            // Define the path for the manifest file
            string manifestFilePath = @"C:\Users\zhika\OneDrive\Desktop\cs179\readManifest\manifest.txt"; // Change this path as needed

            // Add a note to the log file
            LogManager.AddNoteToLogFile(logFilePath, "Sample Container added to the list.");

            LogManager.CheckOrCreateFile(@"C:\Users\zhika\OneDrive\Desktop\cs179\readManifest\log1.txt");

            LogManager.AddNoteToLogFile(logFilePath, "Sample Container added to the list.");
            LogManager.CheckOrCreateFile(logFilePath);

            List<List<Container>> ship = ManifestManager.ReadManifest(manifestFilePath);
            Console.WriteLine("Ship's Manifest:");
            ManifestManager.Print(ship);

            // Update the manifest file
            ship[6][1].Name = "abc";
            ship[7][2].Name = "qqq";
            ManifestManager.UpdateManifest(ship, manifestFilePath);
            ManifestManager.Print(ship);
        }
    }
}
