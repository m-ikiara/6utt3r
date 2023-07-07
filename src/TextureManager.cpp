/* Copyright [2023] <Brian M'Ikiara> */
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
  SDL_Surface* tempSurface = IMG_Load(texture);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(
    Butt3r::renderer, tempSurface);
  SDL_FreeSurface(tempSurface);

  return tex;
}

void TextureManager::Draw(
  SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip) {
  SDL_RenderCopyEx(Butt3r::renderer, tex, &src, &dest, NULL, NULL, flip);
}
