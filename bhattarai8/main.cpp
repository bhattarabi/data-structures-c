#include <iostream>
#include "hashtable.h"
#include "symbol.h"
using namespace std;

const int TABLE_SIZE=13;

int hash(const Symbol& value)
{
   int val=0;
   string s = value.getSymbol();
   for (int i=0; i<s.length(); i++)
      val += static_cast<int>(s[i]);
   return val%TABLE_SIZE;
}

int hash2(const int& value)
{
   return value%TABLE_SIZE;
}

int main()
{
// Symbol must have operator== overloaded
   HashTable<Symbol> hashtable(TABLE_SIZE,hash);
   Symbol s;
   s.setSymbol("hello");
   s.setValue(1);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
    
   if (!hashtable.search(s))
   {
      hashtable.insert(s);
      cout << s << " entered\n";
   }
   else
   {
      cout << s << " already in the table, not entered\n";
   }
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("there");
   s.setValue(2);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("how");
   s.setValue(3);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("are");
   s.setValue(4);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("you");
   s.setValue(5);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("I");
   s.setValue(6);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("am");
   s.setValue(7);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("fine");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("banana");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("orange");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("pear");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";
   s.setSymbol("peach");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hashtable.hash(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.Collisions() << " collisions\n";

   cout << "--------------------------------------------------------------\n";

   Symbol s2;
   s2.setSymbol("am");
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";
   s2.setSymbol("how");
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";
   s2.setSymbol("baseball");
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";

   cout << "there were " << hashtable.Collisions() << " collisions\n";

   cout << "--------------------------------------------------------------\n";

   HashTable<int> hashtable2(TABLE_SIZE,hash2);
   int num=57;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=24;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=45;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=17;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=78;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   cout << "there were " << hashtable2.Collisions() << " collisions\n";
	
   return 0;
}

