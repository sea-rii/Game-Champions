#include "champion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Champion* createChampion()
{
  Champion* c = (Champion*)malloc(sizeof(Champion));
  int t = rand() % 4;
  if (t==0)
  {
    c->role = MAGE;
    c->level = rand() % 4 + 5;
  }
  else if (t==1)
  {
    c->role = FIGHTER;
    c->level = rand() % 4 + 1;
  }
  else if (t==2)
  {
    c->role = SUPPORT;
    c->level = rand() % 4 + 3;
  }
  else
  {
    c->role = TANK;
    c->level = rand() % 8 + 1;
  }
  c->next = NULL;
  return c;
}

Champion* addChampion( Champion *head, Champion *c )
{
  Champion* curr = head;
  if (curr == NULL)
  {
    return c;
  }
  if (curr->level < c->level)
  {
    c->next = curr;
    return c;
  }
  while (curr->next != NULL)
  {
    if (curr->next->level < c->level)
    {
      break;
    }
    curr = curr->next;
  }
  c->next = curr->next;
  curr->next = c;
  
  return head;
}

Champion* buildChampionList( int n )
{
  Champion* h;
  Champion* temp;
  int i;
  for (i=0; i < n; i++)
  {
    temp = createChampion();
    addChampion(h, temp);
  }
}

void printChampionList( Champion *head )
{
  Champion* p;
  for (p = head; p != NULL; p = p->next)
  {
    if (p->role == MAGE)
    {
      printf("M%d ", p->level);
    }
    else if (p->role == FIGHTER)
    {
      printf("F%d ", p->level);
    }
    else if (p->role == SUPPORT)
    {
      printf("S%d ", p->level);
    }
    else
    {
      printf("T%d ", p->level);
    }
    printf("\n");
  }
}

Champion* removeChampion( Champion *head )
{
  if (head != NULL)
  {
    Champion* temp = head;
    head = head->next;
    free(temp);
  }
  return head;
}

Champion* destroyChampionList( Champion *head )
{
  Champion* p = head;
  while (p != NULL)
  {
    Champion* temp = p;
    p = p->next;
    free(temp);
  }
  return NULL;
}
