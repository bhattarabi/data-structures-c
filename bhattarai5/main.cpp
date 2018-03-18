//File:      main.cpp
//Name:      Binaya Bhattarai
//Class:     CSIS 352
//Program:   assignment 5
//Date:      3/30/2016

//This file contains main program for assignment 5.

#include <iostream>
#include "graph.h"
#include "city.h"
using namespace std;
using namespace GraphNameSpace;

int main()
{

   Graph<City> map(DIRECTED,WEIGHTED);

   City Fargo("Fargo");
   City Minneapolis("Minneapolis");
   City Chicago("Chicago");
   City Detroit("Detroit");
   City NewYork ("New York");
   City Miami("Miami");
   City StLouis("St. Louis");
   City Houston("Houston");
   City Denver("Denver");
   City Phoenix("Phoenix");
   City LosAngeles("Los Angeles");
   City Seattle("Seattle");

   try
   {
      map.insertVertex(Seattle);
      map.insertVertex(LosAngeles);
      map.insertVertex(Phoenix);
      map.insertVertex(Denver);
      map.insertVertex(Fargo);
      map.insertVertex(Minneapolis);
      map.insertVertex(Houston);
      map.insertVertex(StLouis);
      map.insertVertex(Chicago);
      map.insertVertex(Detroit);
      map.insertVertex(Miami);
      map.insertVertex(NewYork);
   }
   catch (logic_error error)
   {
      cout << error.what() << endl;
   }

   try
   {
      map.insertEdge(Fargo,Minneapolis,240);
      map.insertEdge(Minneapolis,Fargo,240);
      map.insertEdge(Minneapolis,Chicago,409);
      map.insertEdge(Minneapolis,Denver,920);
      map.insertEdge(Chicago,Minneapolis,409);
      map.insertEdge(Chicago,Detroit,286);
      map.insertEdge(Chicago,NewYork,821);
      map.insertEdge(Detroit,Chicago,286);
      map.insertEdge(Detroit,StLouis,547);
      map.insertEdge(Detroit,NewYork,640);
      map.insertEdge(NewYork,Miami,1281);
      map.insertEdge(NewYork,LosAngeles,2824);
      map.insertEdge(NewYork,Chicago,821);
      map.insertEdge(Miami,NewYork,1281);
      map.insertEdge(Miami,Houston,1190);
      map.insertEdge(StLouis,Detroit,547);
      map.insertEdge(StLouis,Denver,861);
      map.insertEdge(Houston,StLouis,780);
      map.insertEdge(Houston,Miami,1190);
      map.insertEdge(Houston,Phoenix,1186);
      map.insertEdge(Phoenix,Houston,1186);
      map.insertEdge(Phoenix,LosAngeles,381);
      map.insertEdge(LosAngeles,Phoenix,381);
      map.insertEdge(LosAngeles,NewYork,2824);
      map.insertEdge(LosAngeles,Denver,1023);
      map.insertEdge(LosAngeles,Seattle,1151);
      map.insertEdge(Denver,Minneapolis,920);
      map.insertEdge(Denver,LosAngeles,1023);
      map.insertEdge(Seattle,Chicago,2072);
      map.insertEdge(Fargo,Denver,909);
      map.insertEdge(Seattle,Denver,1332);
   }
   catch (logic_error error)
   {
      cout << error.what() << endl;
   }

   cout << "vertex count = " << map.vertexCount() << endl;
   map.dump();

   return 0;
}
