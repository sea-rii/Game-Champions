#ifndef CHAMPION_H
#define CHAMPION_H

typedef enum ChampionRole {MAGE, FIGHTER, SUPPORT, TANK} ChampionRole;
typedef struct Champion
{
  int level;   
  ChampionRole role;
  struct Champion *next;

} Champion; 

Champion* createChampion();
Champion* addChampion( Champion *head, Champion *c );
Champion* buildChampionList( int n );
void printChampionList( Champion* head );
Champion* removeChampion( Champion *head );
Champion* destroyChampionList( Champion *head );

#endif
