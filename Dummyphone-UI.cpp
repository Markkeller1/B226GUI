#pragma once
#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h

#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads
#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

std::string colour1 = "Not chosen", colour2 = "Not chosen", Type = "Not chosen", Fuse = "Not chosen", engraving = "Not chosen";
int ctype = 1, imagechoice1 = 0, imagechoice2 = 0, imagechoice3 = 0, imagechoice4 = 0, Fusechoice = 0;



int main()
{
    

    


    sf::RenderWindow window(sf::VideoMode(1000, 600), "Dummy phone UI");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    static bool Finished = false;
    
    sf::Texture texture;
    sf::Clock deltaClock;
    sf::Sprite sprite;

    


    
    

    while (window.isOpen())
    {
            sf::Event event;
            while (window.pollEvent(event)) 
            {
                ImGui::SFML::ProcessEvent(event);

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("options");

        

            //Window 1 start
            if (ImGui::Button("Bottom cover colour"))
            {
                bool setting_chosen = 1;
                if (setting_chosen == 1)
                {
                ImGui::OpenPopup("Window 1");
                }
            }
            if (ImGui::BeginPopupModal("Window 1"))
            {   
                if (ImGui::Button("Black"))
                {
                    colour1 = "Black";
                    imagechoice1 = 1;
                    ImGui::CloseCurrentPopup();
                    
                }
            if (ImGui::Button("White"))
                {
                    colour1 = "White";
                    imagechoice1 = 2;
                    ImGui::CloseCurrentPopup();
                    
                }
            if (ImGui::Button("Blue"))
                {
                    colour1 = "Blue";
                    imagechoice1 = 3;
                    ImGui::CloseCurrentPopup();
                    
                }

                ImGui::EndPopup();
            }


            //Window 1 end


            //Window 2 start
            if (ImGui::Button("Top Cover Type     "))
            {
                bool setting_chosen = 1;
                if (setting_chosen == 1)
                {
                ImGui::OpenPopup("Window 2");
                }
            }
            if (ImGui::BeginPopupModal("Window 2"))
            {
                
                
                if (ImGui::Button("Flat"))
                {
                    ctype = 2;
                    imagechoice2 = 1;
                    Type = "Flat";
                    ImGui::CloseCurrentPopup();
                    
                }
                if (ImGui::Button("Curved"))
                {
                    ctype = 3;
                    imagechoice2 = 2;
                    Type = "Curved";
                    ImGui::CloseCurrentPopup();
                    
                }
                

                ImGui::EndPopup();
            }
            //Window 2 end
        
        
        //Window 3 start
        if (ImGui::Button("Top Cover colour   "))
            {
                bool setting_chosen = 1;
                if (setting_chosen == 1)
                {
                ImGui::OpenPopup("Window 3");
                }
            }
            if (ImGui::BeginPopupModal("Window 3"))
            {
                switch (ctype)
                {
                case 1:
                    ImGui::Text("Please select top cover type.");
                    if (ImGui::Button("close"))
                    {
                    ImGui::CloseCurrentPopup();
                    
                    }
                    break;
                case 2:
                    if (ImGui::Button("Black"))
                    {
                        colour2 = "Black";
                        imagechoice3 = 1;
                        ImGui::CloseCurrentPopup();
                    }
                    if (ImGui::Button("white"))
                    {   
                        colour2 = "White";
                        imagechoice3 = 2;
                        ImGui::CloseCurrentPopup();
                    }
                    if (ImGui::Button("Blue"))
                    {
                        colour2 = "Blue";
                        imagechoice3 = 3;
                        ImGui::CloseCurrentPopup();
                    }
                    break;
                case 3:
                    if (ImGui::Button("Pink"))
                    {
                        colour2 = "Pink";
                        imagechoice3 = 1;
                        ImGui::CloseCurrentPopup();
                    }

                    break;
                
                }

                ImGui::EndPopup();
            }
            //Window 3 end  

            //Window 4 start
        if (ImGui::Button("Fuses              "))
            {
                bool setting_chosen = 1;
                if (setting_chosen == 1)
                {
                ImGui::OpenPopup("Window 4");
                }
            }
            if (ImGui::BeginPopupModal("Window 4"))
            {
                Fusechoice = 1;
                
                if (ImGui::Button("0"))
                {
                    Fuse = "0";
                    ImGui::CloseCurrentPopup();
                    
                }
                if (ImGui::Button("1"))
                {
                    Fuse = "1";
                    ImGui::CloseCurrentPopup();
                    
                }
                if (ImGui::Button("2"))
                {
                    Fuse = "2";
                    ImGui::CloseCurrentPopup();
                    
                }

                ImGui::EndPopup();
            }
        //Window 4 end
        //window 5 start
            if (ImGui::Button("Engraving          "))
            {
                bool setting_chosen = 1;
                if (setting_chosen == 1)
                {
                ImGui::OpenPopup("Window 5");
                }
            }
            if (ImGui::BeginPopupModal("Window 5"))
            {
                if (ImGui::Button("AAU logo"))
                {
                    engraving = "AAU logo";
                    imagechoice4 = 1;
                    ImGui::CloseCurrentPopup();
                    
                }
                if (ImGui::Button("B226"))
                    {
                        engraving = "B226";
                        imagechoice4 = 2;
                        ImGui::CloseCurrentPopup();
                        
                    }

                if (ImGui::Button("AAU logo & B226"))
                    {
                        engraving = "AAU logo & B226";
                        imagechoice4 = 3;
                        ImGui::CloseCurrentPopup();
                        
                    }

                if (ImGui::Button("No engraving"))
                    {
                        engraving = "No engraving";
                        imagechoice4 = 4;
                        ImGui::CloseCurrentPopup();
                        
                    }


                ImGui::EndPopup();
            }
        //window 5 end
        //done start
        if(imagechoice1 != 0 && imagechoice2 != 0 && imagechoice3 != 0 && imagechoice4 != 0 && Fusechoice != 0)
                if (ImGui::Button("Done               "))
                {
                    bool setting_chosen = 1;
                    if (setting_chosen == 1)
                    {
                    sprite.setTexture(texture);
                    Finished = true;
                    std::cout << "Bottom cover:     " << colour1 << std::endl;
                    std::cout << "Top cover type:   " << Type << std::endl;
                    std::cout << "Top cover colour: " << colour2 << std::endl;
                    std::cout << "nr. of fuses:     " << Fuse << std::endl;
                    
                    }
                }
        //done end
        
        switch (imagechoice1)
        {
            case 1:
                //Black Bottom cover
                switch (imagechoice2)
                {
                case 1:
                    //Flat top cover
                    switch (imagechoice3)
                    {
                    case 1:
                        //Black top cover
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/BlackBlack.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                                }
                            break;
                        }
                        
                           
                        
                        break;
                    
                    case 2:
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/BlackWhite.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                            break;
                        }
                        //White top cover
                        
                        break;
                    
                    case 3:
                        //Blue top cover
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/BlackBlue.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                            break;
                        }
                       
                        break;
                    }


                    break;
                
                case 2:
                    //Curved top cover
                        switch (imagechoice3)
                        {
                        case 1:
                            // Pink
                            switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                    if (!texture.loadFromFile("res/BlackPink.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                            break;
                        }
                    



                break;
                }



            break;

            case 2:
                //White Bottom cover
                switch (imagechoice2)
                {
                case 1:
                    //Flat top cover
                    switch (imagechoice3)
                    {
                    case 1:
                        //Black top cover
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/WhiteBlack.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                            break;
                        }
                        
                        break;
                    
                    case 2:
                        //White top cover
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/WhiteWhite.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                            break;
                        }
                        break;
                    
                    case 3:
                        //Blue top cover
                        switch (imagechoice4)
                        {
                        case 1:
                            //AAU logo
                            break;
                        case 2:
                            //B226
                            break;
                        case 3:
                            //AAU logo & B226
                            break;
                        case 4:
                            //No engraving
                            if (!texture.loadFromFile("res/WhiteBlue.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                        break;
                        }
                    }

                    
                    
                    
                    break;
                case 2:
                    //Curved top cover
                    switch (imagechoice3)
                        {
                        case 1:
                            // Pink
                            switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                    if (!texture.loadFromFile("res/WhitePink.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                        break;    
                        }
                break;      
                }
            break;

            case 3:
                //Blue Bottom cover
                switch (imagechoice2)
                {
                case 1:
                    //Flat top cover
                switch (imagechoice2)
                {
                case 1:
                    //Flat top cover
                    switch (imagechoice3)
                    {
                    case 1:
                        //Black top cover
                        switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                if (!texture.loadFromFile("res/BlueBlack.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                        
                        break;
                    
                    case 2:
                        //White top cover
                        switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                if (!texture.loadFromFile("res/BlueWhite.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                        break;
                    
                    case 3:
                        //Blue top cover
                        switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                if (!texture.loadFromFile("res/BlueBlue.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                        break;
                
                    
                    }
                case 2:
                    //Curved top cover
                    switch (imagechoice3)
                        {
                        case 1:
                            // Pink
                            switch (imagechoice4)
                            {
                            case 1:
                                //AAU logo
                                break;
                            case 2:
                                //B226
                                break;
                            case 3:
                                //AAU logo & B226
                                break;
                            case 4:
                                //No engraving
                                    if (!texture.loadFromFile("res/BluePink.jpg"))
                            {
                                std::cout << "Load Failed \n";
                                system("pause");
                            }
                                break;
                            }
                            break;
                        }
                    break;

                    
                }
            }
            
        }
    
   

    
        
         //do not write beyond this point
        ImGui::End();
        window.clear(sf::Color(4,94,212));
        if (Finished == true)
        {
            window.draw(sprite);
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}