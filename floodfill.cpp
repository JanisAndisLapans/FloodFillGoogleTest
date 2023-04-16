#include "floodfill.h"

void floodFill(vector<string> &text, const pair<int, int> &coord) {

  /*
    Funkcija “aizkrāso” doto teksta lauku ar simboliem “#” līdz robežu simboliem “*” (Jebkurš
    cits simbols netiks uztverts kā robežu simbols un tiks “aizkrāsots” ar “#”) vai līdz teksta lauka
    robežām sākot no kāda noteikta punkta, ko ievada lietotājs ar x un y koordinātām.
  */

   const char SEP = '*',
              FILL = '#';

  //Pārbauda vai x un y koordināta nav ārpus robežām
  if(!(coord.second < text.size() && coord.second >= 0 && coord.first < text[coord.second].size() &&  coord.first >= 0))
  {
    throw "Punkts arpus robezam";
  }
  queue<pair<int, int>> q;

  auto [startX, startY] = coord;
 //Jāatskaita 1, lai pārveidotu koordinātu par indeksu (kas sākas ar 0)
  startX--;
  startY--;

  if(text[startY][startX] != SEP){ // Ja sākuma x,y pozīcija ir vienāda ar SEP neko nav jādara
      text[startY][startX] = FILL;
      q.push(coord);
  }

  //Pēc BFS algoritma aizpilda līdz SEP vai robežām
  while (q.size() > 0) {
    auto [x, y] = q.front();
    q.pop();

    if (x + 1 < text[y].size() && text[y][x + 1] != FILL && text[y][x + 1] != SEP) {
      text[y][x+1] = FILL;
      q.push(make_pair(x + 1, y));
    }
    if (x - 1 >= 0 && text[y][x - 1] != FILL && text[y][x - 1] != SEP) {
      text[y][x-1] = FILL;
      q.push(make_pair(x - 1, y));
    }
    if (y + 1 < text.size() && text[y + 1][x] != FILL && text[y + 1][x] != SEP) {
      text[y+1][x] = FILL;
      q.push(make_pair(x, y + 1));
    }
    if (y - 1 >= 0 && text[y - 1][x] != FILL && text[y - 1][x] != SEP) {
      text[y-1][x] = FILL;
      q.push(make_pair(x, y - 1));
    }
  }
}