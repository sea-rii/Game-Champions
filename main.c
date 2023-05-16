#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    printf("Error: missing command line argument.\n");
    return 1;
  }
  int size = atoi(argv[1]);
  if (size <= 0)
  {
    printf("Error: invalid size.\n");
    return 1;
  }
  srand(time(NULL));
  Champion* player1 = buildChampionList(size);
  Champion* player2 = buildChampionList(size);
  printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN =============\n");
  int i = 1;
  Champion* temp;
  
  while (player1 != NULL && player2 != NULL)
  {
    printf("----- ROUND %d -----", i++);
    printf("Player 1: ");
    printChampionList(player1);
    printf("Player 2: ");
    printChampionList(player2);
    
    if (player1->role == MAGE && player2->role == MAGE)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (MAGE) wins and gains one new champion.\n");
        printf("Player 2 (MAGE) loses one champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player1, temp);
        player2 = removeChampion(player2);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (MAGE) loses one champion.\n");
        printf("Player 2 (MAGE) wins and gains one new champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player2 = addChampion(player2, temp);
        player1 = removeChampion(player1);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == FIGHTER && player2->role == MAGE)
    {
       if (player1->level > player2->level)
      {
        printf("Player 1 (FIGHTER) wins and gains no reward.\n");
        printf("Player 2 (MAGE) loses one champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        player2 = removeChampion(player2);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (FIGHTER) loses with no penalty.\n");
        printf("Player 2 (MAGE) wins and gains a new champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player2 = addChampion(player2, temp);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == SUPPORT && player2->role == MAGE)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
        printf("Player 2 (MAGE) loses one champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player1, temp);
        temp = createChampion();
        player1 = addChampion(player1,temp);
        player2 = removeChampion(player2);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (MAGE) wins and gains a new champion.\n");
        printf("Player 2 (SUPPORT) loses two champions.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player2, temp);
        player2 = removeChampion(player2);
        player2 = removeChampion(player2);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == TANK && player2->role == MAGE)
    {
      printf("Player 1 (TANK) loses the next champion.\n");
      printf("Player 2 (MAGE) wins and gains a new champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      player1 = removeChampion(player1);
      temp = createChampion();
      player2 = addChampion(player2, temp);
    }
    
    else if (player1->role == MAGE && player2->role == FIGHTER)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (MAGE) wins and gains a new champion.\n");
        printf("Player 2 (FIGHTER) loses with no penalty.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player1, temp);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (MAGE) loses a new champion.\n");
        printf("Player 2 (FIGHTER) wins and gains no reward.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        player1 = removeChampion(player1);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == FIGHTER && player2->role == FIGHTER)
    {
      printf("Player 1 (FIGHTER) gains a new champion.\n");
      printf("Player 2 (FIGHTER) gains a new champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp = createChampion();
      player1 = addChampion(player1, temp);
      temp = createChampion();
      player2 = addChampion(player2,temp);
    }
    else if (player1->role == SUPPORT && player2->role == FIGHTER)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (SUPPORT) wins and gains a new champion.\n");
        printf("Player 2 (FIGHTER) loses with no penalty.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player1, temp);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (SUPPORT) loses one champion.\n");
        printf("Player 2 (FIGHTER) wins but gains no reward.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        player1 = removeChampion(player1);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == TANK && player2->role == FIGHTER)
    {
      printf("Player 1 (TANK) loses but with no penalty.\n");
      printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp = createChampion();
      player2 = addChampion(player2, temp);
    }
    
    else if (player1->role == MAGE && player2->role == SUPPORT)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (MAGE) wins and gains one new champion.\n");
        printf("Player 2 (SUPPORT) loses two champions.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player1 = addChampion(player1, temp);
        player2 = removeChampion(player2);
        player2 = removeChampion(player2);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (MAGE) loses a new champion.\n");
        printf("Player 2 (SUPPORT) wins and gains two new champions.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player2 = addChampion(player2, temp);
        temp = createChampion();
        player2 = addChampion(player2, temp);
        player1 = removeChampion(player1);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == FIGHTER && player2->role == SUPPORT)
    {
      if (player1->level > player2->level)
      {
        printf("Player 1 (FIGHTER) wins but gains no reward.\n");
        printf("Player 2 (SUPPORT) loses one champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        player2 = removeChampion(player2);
      }
      else if (player1->level < player2->level)
      {
        printf("Player 1 (FIGHTER) loses with no penalty.\n");
        printf("Player 2 (SUPPORT) wins and gains a new champion.\n");
        
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        temp = createChampion();
        player2 = addChampion(player2, temp);
      }
      else
      {
        printf("Tie. Nothing happens\n");
        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
      }
    }
    
    else if (player1->role == SUPPORT && player2->role == SUPPORT)
    {
      printf("Both players lose the next champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
    }
    
    else if (player1->role == TANK && player2->role == SUPPORT)
    {
      printf("Player 1 (TANK) wins and gains a new champion.\n");
      printf("Player 2 (SUPPORT) loses but with no penalty.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp = createChampion();
      player1 = addChampion(player1, temp);
    }
    
    else if (player1->role == MAGE && player2->role == TANK)
    {
      printf("Player 1 (MAGE) wins and gain a new champion.\n");
      printf("Player 2 (TANK) loses the next champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp =createChampion();
      player1 = addChampion(player1, temp);
      player2 = removeChampion(player2);
    }
    
    else if (player1->role == FIGHTER && player2->role == TANK)
    {
      printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
      printf("Player 2 (TANK) loses but with no penalty.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp = createChampion();
      player1 = addChampion(player1, temp);
    }
    
    else if (player1->role == SUPPORT && player2->role == TANK)
    {
      printf("Player 1 (SUPPORT) looses but with no penalty.\n");
      printf("Player 2 (TANK) wins and gains a new champion.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
      temp = createChampion();
      player2 = addChampion(player2, temp);
    }
    
    else 
    {
      printf("Nothing happens - no penalty or no reward.\n");
      player1 = removeChampion(player1);
      player2 = removeChampion(player2);
    }
  }
  
  printf("============= GAME OVER =============\n");
  printf("Player 1 ending champion list: ");
  printChampionList(player1);
  printf("Player 2 ending champion list: ");
  printChampionList(player2);
  printf("\n");
  
  if (player1 == NULL && player2 == NULL)
  {
    printf("TIE -- both players ran out of champions.\n");
  }
  else if (player1 != NULL)
  {
    printf("Player 2 ran out of champions. Player 1 wins.\n");
  }
  else
  {
    printf("player 1 ran out of champions. Player 2 wins.\n");
  }
  
  destroyChampionList(player1);
  destroyChampionList(player2);
  

  return 0;
}
