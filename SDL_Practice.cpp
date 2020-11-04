//// SDL_Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//
//#define SDL_MAIN_HANDLED 
//#include <SDL.h>
//
//int main() {
//    SDL_Window* window = NULL;
//
//    SDL_Surface *windowSurface = NULL, *imageSurface = NULL;
//
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cout << "Faild to initialize SDL" << std::endl;
//        return -1;
//    }
//
//    imageSurface = SDL_LoadBMP("./test.bmp");
//    if (imageSurface == NULL) {
//        std::cout << "Error loading image file" << std::endl;
//        return -1;
//    }
//
//    window = SDL_CreateWindow("damay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
//    if (window == NULL) {
//        //std::cout << "Faild to initialize SDL" << std::endl;
//        std::cout << "Error creating SDL window" << std::endl;
//        return -1;
//    }
//
//    windowSurface = SDL_GetWindowSurface(window);
//
//    /*SDL_Delay(2000);*/
//
//    bool quit = false;
//    while (!quit) {
//        SDL_Event event;
//        while (SDL_PollEvent(&event) != 0) {
//            if (event.type == SDL_QUIT) {
//                quit = true;
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_x) {
//                quit = true;
//            }
//
//        }
//        SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 255, 255, 255));
//        SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
//
//        SDL_UpdateWindowSurface(window);
//    }
//
//    SDL_FreeSurface(imageSurface);
//
//    SDL_DestroyWindow(window);
//
//    SDL_Quit();
//
//    return 0;
//
//
//}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file