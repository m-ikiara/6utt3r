/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _MAP_H_
#define _MAP_H_

#pragma once
#include <string>

class Map {
 public:
  Map(std::string tID, int ms, int ts);
  ~Map();

  void LoadMap(std::string path, int sizeX, int sizeY);
  void AddTile(int srcX, int srcY, int xpos, int ypos);

 private:
  std::string texID;
  int mapScale;
  int tileSize;
  int scaledSize;
};

#endif /* _MAP_H_ */

