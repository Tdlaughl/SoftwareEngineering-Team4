# SoftwareEngineering

# Github names to real names
| Github Name  | Actual Name |
| ------------- | ------------- |
| tdlaughl  | Trenton Laughlin |
| MoisesUrrutia | Moises Urrutia |
| HovigJawichian | Hovig Jawichian |
| Kaiba-156 | Carl von Bergen |
| ChrisMorale | Chris Morales |

# What script to run to get all of the downloads
To get the code to work you will run the script called "run.sh" to download all of the files you would need for the project. (curl, SFML, g++, etc.) To do that you need to run "chmod +x run.sh" first then run "./run.sh"
To compile the program first get into the PlayerEntry+Database directory. Then run g++ -Wall *.cpp -o PlayerEntry.exe -lsfml-graphics -lsfml-window -lsfml-system -lcurl. Then run ./PlayerEntry.exe
