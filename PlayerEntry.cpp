#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Player {
    public:
        std::string name;
        std::string ID;
        int points;

    Player(const std::string& n, const std::string& i , int p) : name(n), ID(i), points(p) {}
};





struct Cell {
    sf::RectangleShape rect;
    sf::Text text;
    std::string playerName;
    int playerPoints;

    Cell() : playerName(""), playerPoints(0) {}
};

// void setRectangle(sf::RectangleShape rec,  float posX, float posY)
// {
//     rec.setSize(sf::Vector2f(200.f, 100.f));
//     rec.setPosition(posX, posY);

// };

int main() {
    
    std::string enterName = "test";
    std::string enterID = "12";
    //Player enterPlayer(enterName, enterID, 0);


    // Create a list of players
    std::vector<Player> playerListRed = {
        // {"Player1", 10},
        // {"Player2", 5},
        // {"Player3", 8},
        // Add more players as needed
    };

    std::vector<Player> playerListGreen = {
        // {"Player1", 10},
        // {"Player2", 5},
        // {"Player3", 8},
        // Add more players as needed
    };

    int windowSizeX = 1250;
    int windowSizeY = 900;
    sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Player Entry Screen");

    const int rows = 20;
    const int columns = 2;
    const float cellWidth = 150.f;
    const float cellHeight = 30.f;

    std::vector<std::vector<Cell>> team1Table(rows, std::vector<Cell>(columns));
    std::vector<std::vector<Cell>> team2Table(rows, std::vector<Cell>(columns));


    Player enterPlayer1(enterName, enterID, 0);
    Player enterPlayer2(enterName, enterID, 0);

    sf::RectangleShape rectangleRed, rectangleGreen;

    //Controls when the program goes to the play action screen.
    bool playAction = 0;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {


            if (event.type == sf::Event::Closed) {
                window.close();
            } 
            else if (event.type == sf::Event::TextEntered) {
                // Handle text input events
                if (event.text.unicode < 128) {
                    char inputChar = static_cast<char>(event.text.unicode);

                    // Iterate through cells to find the active cell
                    for (size_t i = 0; i < rows; ++i) {
                        for (size_t j = 0; j < columns; ++j) {
                            if (team1Table[i][j].rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                                // // Handle Enter key to commit changes
                                // // 
                                // if (inputChar == 13) {
                                //     team1Table[i][j].text.setString(team1Table[i][j].playerName);
                                //     //std::cout <<  (team1Table[i][j].playerName);

                                // } 
                                
                                if (inputChar == 8) {
                                    // Backspace deletes characters
                                    if (!team1Table[i][j].playerName.empty()) {
                                        team1Table[i][j].playerName.pop_back();
                                    }
                                } else {
                                    // Append the character to the input string
                                    if (team1Table[i][j].playerName.size() < 15) {  // Limit the player name length
                                        team1Table[i][j].playerName += inputChar;
                                    }
                                }

                            } 


                            if (team2Table[i][j].rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                                // Similar handling for the second team
                                if (inputChar == 13) {
                                    team2Table[i][j].text.setString(team2Table[i][j].playerName);
                                } else if (inputChar == 8) {
                                    if (!team2Table[i][j].playerName.empty()) {
                                        team2Table[i][j].playerName.pop_back();
                                    }
                                } else {
                                    if (team2Table[i][j].playerName.size() < 15) {
                                        team2Table[i][j].playerName += inputChar;
                                    }
                                }

                            }
                        }
                    }
                }
            }
            
        }

        window.clear();

        if (sf::Keyboard:: isKeyPressed(sf::Keyboard::F12))
        {
            std::cout << "hello" << std::endl;
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    team1Table[i][j].text.setString("");
                    team2Table[i][j].text.setString("");
                    team1Table[i][j].playerName = ("");
                    team2Table[i][j].playerName = ("");
                }
            }
        }

        rectangleRed.setSize(sf::Vector2f(460.f, 850.f));
        rectangleGreen.setSize(sf::Vector2f(460.f, 850.f));

        rectangleRed.setPosition(75.0f, 50.0f);
        rectangleGreen.setPosition((windowSizeX/2)+75.0f, 50.0f);

        rectangleRed.setFillColor(sf::Color::Red);
        rectangleGreen.setFillColor(sf::Color::Green);



        window.draw(rectangleRed);
        window.draw(rectangleGreen);

        // Draw team 1 entry table
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                team1Table[i][j].rect.setSize(sf::Vector2f(150.0f, 30.0f));
                team1Table[i][j].rect.setFillColor(sf::Color::White);  // Set color for team 1
                team1Table[i][j].rect.setPosition(150.0f + j * 160.0f, 100.0f + i * 40.0f);
                window.draw(team1Table[i][j].rect);

                sf::Font font;
                if (font.loadFromFile("arial.ttf")) {
                    team1Table[i][j].text.setFont(font);
                    team1Table[i][j].text.setString(team1Table[i][j].playerName);
                    team1Table[i][j].text.setCharacterSize(12);
                    team1Table[i][j].text.setFillColor(sf::Color::Black);
                    team1Table[i][j].text.setPosition(150.0f + j * 160.0f, 100.0f + i * 40.0f);
                    window.draw(team1Table[i][j].text);
                    
                }
            }

        }
            //playerListRed.push_back(enterPlayer1);
        // Draw team 2 entry table
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                team2Table[i][j].rect.setSize(sf::Vector2f(150.0f, 30.0f));
                team2Table[i][j].rect.setFillColor(sf::Color::White);  // Set color for team 2
                team2Table[i][j].rect.setPosition((windowSizeX/2) + 150.0f + j * 160.0f, 100.0f + i * 40.0f);
                window.draw(team2Table[i][j].rect);

                sf::Font font;
                if (font.loadFromFile("arial.ttf")) {
                    team2Table[i][j].text.setFont(font);
                    team2Table[i][j].text.setString(team2Table[i][j].playerName);
                    team2Table[i][j].text.setCharacterSize(12);
                    team2Table[i][j].text.setFillColor(sf::Color::Black);
                    team2Table[i][j].text.setPosition((windowSizeX/2) + 150.0f + j * 160.0f, 100.0f + i * 40.0f);
                    window.draw(team2Table[i][j].text);
                    
                }
            }
        }
        Cell redTeam;
        Cell greenTeam;
        sf::Font font;
        redTeam.rect.setSize(sf::Vector2f(150.0f, 30.0f));
        redTeam.rect.setFillColor(sf::Color::Red);
        redTeam.rect.setPosition(225.0f, 20.0f);
        window.draw(redTeam.rect);
        
        greenTeam.rect.setSize(sf::Vector2f(150.0f, 30.0f));
        greenTeam.rect.setFillColor(sf::Color::Green);
        greenTeam.rect.setPosition((windowSizeX/2) + 225.0f, 20.0f);
        window.draw(greenTeam.rect);
        if (font.loadFromFile("arial.ttf"))
        {
            redTeam.text.setFont(font);
            redTeam.text.setString("Red Team");
            redTeam.text.setCharacterSize(18);
            redTeam.text.setFillColor(sf::Color::White);
            redTeam.text.setPosition(260.0f, 25.0f);
            window.draw(redTeam.text);
            
            greenTeam.text.setFont(font);
            greenTeam.text.setString("Green Team");
            greenTeam.text.setCharacterSize(18);
            greenTeam.text.setFillColor(sf::Color::White);
            greenTeam.text.setPosition((windowSizeX/2) + 250.0f, 25.0f);
            window.draw(greenTeam.text);
        }
            

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
        {
            playAction = 1;
            window.close();
            //void playAction();
            
        }


        window.display();


  
    }
    
    for (int i = 0; i < rows; ++i)
    {
        // for (int j = 0; j < columns; ++j)
        // {
        //     if (j == 1)
        //         {
        //             enterID = team1Table[i][j].playerName;
        //             enterPlayer1.ID = enterID;
        //         }
        //     else if (j == 2)
        //         {
        //             enterName = team1Table[i][j].playerName;
        //             enterPlayer1.name = enterName;
        //         }       
        // }
        enterID = team1Table[i][0].playerName;
        enterPlayer1.ID = enterID;

        enterName = team1Table[i][1].playerName;
        enterPlayer1.name = enterName;
        playerListRed.push_back(enterPlayer1);



        enterID = team2Table[i][0].playerName;
        enterPlayer2.ID = enterID;

        enterName = team2Table[i][1].playerName;
        enterPlayer2.name = enterName;
        playerListGreen.push_back(enterPlayer2);
    }


    int select = 0;
    int teamSelect = 0;
    

    //Randomly choose one for testing, for implementation 
    int updateShot = 0; //points of shot
    int updateBase = 2;

    // SFML rendering code (optional for visualization)
    if (playAction == 1)
    {
        
        sf::RenderWindow window2(sf::VideoMode(windowSizeX, windowSizeY), "Play Action");

        while (window2.isOpen()) {
            sf::Event event;
            while (window2.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window2.close();
                }
            }

            // SFML rendering
            window2.clear(sf::Color::White);

            // Draw the list of players on the window
            sf::Font font;
            if (font.loadFromFile("arial.ttf")) {  // Provide your own font file
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Red);

                float yPosition = 50.0f;

                for (const auto& player : playerListRed) {
                    if (player.ID != "")
                    {
                    // int points = 0;
                    // std::cin >> points;
                    text.setString(player.ID + "   " + player.name + "   " + std::to_string(player.points));
                    text.setPosition(50.0f, yPosition);
                    window2.draw(text);

                    yPosition += 30.0f; 
                    }

                }


                //printing green team

                yPosition = 50.0f;

                text.setFillColor(sf::Color::Green);

                for (const auto& player : playerListGreen) {
                    if (player.ID != "")
                    {
                        // int points = 0;
                        // std::cin >> points;
                        text.setString(player.ID + "   " + player.name + "   " + std::to_string(player.points));
                        text.setPosition((windowSizeX / 2) + 50.0f, yPosition);
                        window2.draw(text);

                        yPosition += 30.0f;
                    }

                }
            }

            window2.display();
        }

        return 0;
    }
    }
// //cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .

// //mingw32-make clean
// //mingw32-make





/// Enter Id, prompt for the codename in the database, if not in the database, add a new one
//assume ids are unique, codenames can be duplicated