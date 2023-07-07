/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _UILABEL_H_
#define _UILABEL_H_

#pragma once

#include <string>
#include "ECS.h"
#include "../AssetManager.h"
#include "../Butt3r.h"
#include "../../SDL2/include/SDL.h"
#include "../../SDL2/include/SDL_ttf.h"

class UILabel : public Component {
 public:
  UILabel(
    int xpos, int ypos,
    std::string text, std::string font, SDL_Color &colour)
    : labelText(text), labelFont(font), textColour(colour) {
    position.x = xpos;
    position.y = ypos;

    SetLabelText(labelText, labelFont);
  }
  ~UILabel()
  {}

  void SetLabelText(std::string text, std::string font) {
    SDL_Surface* surf = TTF_RenderText_Blended(
      Butt3r::assets->GetFont(font), text.c_str(), textColour);
    labelTexture = SDL_CreateTextureFromSurface(Butt3r::renderer, surf);
    SDL_FreeSurface(surf);

    SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
  }

  void draw() override {
    SDL_RenderCopy(Butt3r::renderer, labelTexture, nullptr, &position);
  }

 private:
  SDL_Rect position;
  std::string labelText;
  std::string labelFont;
  SDL_Color textColour;
  SDL_Texture* labelTexture;
};

#endif /* _UILABEL_H_ */

