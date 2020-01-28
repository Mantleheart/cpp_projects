//------------------------------------------------------------
// Purpose: To implement an online "Man vs. Wild: Mountain Special"
//          game.  Mountain locations are described by separate functions.
//          The user playing the game finds "food" and "water" as 
//          they do different activities.
//
// Author:  Caleb Duke
//------------------------------------------------------------

// include statements

#include <cstdlib>
#include <stdio.h>
#include <iostream>


using namespace std;

// Function prototypes
int FindWater(int max_water);
void GainFood(int max_food, int & food_gained);
char GetDirection();
int partysize;

//Functions for locations
void Exit(int &water, int &food);
void Mountain1(int &water, int &food);
void Mountain2(int &water, int &food);
void Mountain3(int &water, int &food);
void Mountain4(int &water, int &food);

//Functions for events
void intro(int &partysize);
int gameover(); 
void clearscreen(int i);              
void drawparty(int &partysize);  


//------------------------------------------------------------
// Purpose: To calculate how much water user has.
// Input:   Maximum water (int -100..100).     
// Output:  Actual water (int -100..100).
//------------------------------------------------------------

int FindWater(int max_water)
   {
   // Range checking of parameters
   if (max_water < -100) max_water = -100;
   if (max_water >  100) max_water =  100;

   cout << "Do you want to pick this bottled water up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle yes answer
   int water = 60;
   if (answer == "yes")
   {
      float fraction = (1.0 + random() % 100) / 100.0;
      water = fraction * max_water;
      if (water > 0)
         cout << "You found " << water << " L water " << endl;
      else
         cout << "You fell down and lost " << water << " L water" << endl;
   } 

   // Handle no answer
   else if (answer == "no")
   { 
      if (max_water > 0)
         cout << "Too bad, you need around 4-5 liters of water at altitude to feel great" << endl;
      else      
         cout << "Good thing you didn't get it, it is empty" << endl;
   }

   // Handle wrong answer
   else 
   { 
      cout << "A simple 'yes' or 'no' would be nice..." << endl;
      cout << "Better luck next time you see an item" << endl;
   }
   return water;
   }

//------------------------------------------------------------
// Purpose: To calculate how much food user has.
// Input:   Maximum food (int 1..100).
// Output:  Actual food gained (int 1..100).
//------------------------------------------------------------
void GainFood(int max_food, int & food_gained)
   {
   // Range checking of parameters
   if (max_food < 1)  max_food = 1;
   if (max_food > 100) max_food = 100;

   cout << "Do you want to pick this airdropping package up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle help answer
   if (answer == "yes")
   {
      food_gained = 1 + random() % max_food;
      cout << "Congratulations, you gained " << food_gained << " food points" << endl;
   } 

   // Handle other answers
   else 
   { 
      food_gained = -(1 + random() % max_food);
      if (random() % 2 == 0)
         cout << "Illusion! Thats not a real package" << endl;
      else
         cout << "You lost " << food_gained << " food points" << endl;
   }
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }
   return direction;
}

//------------------------------------------------------------
// Purpose: The ending Mountain for the game
// Input:   The water and food variables 
// Output:  None
//------------------------------------------------------------

void Exit(int &water, int &food)
   {
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou have already finished the summits challenge\n";
   cout << "I hope you enjoyed this trip\n";
   cout << "You got \n";
   cout << "\nWater: " << water << " Food: " << food << endl;
   
   // Give prizes
   if (water <= 0) 
   {
      cout << "\nYou feel thirsty and give up climbing other highest point in the world, but at least you made it to the city!\n";
    
   }
   else if (food <= 0)
   {
      cout << "\nYou feel hungry and give up climbing other highest point in the world, but at least you made it to the city!\n";
   }
   else if (food == 0)
   {
      cout << "\nYou feel hungry and give up climbing other highest point in the world, but it was worth it to make it here.\n";
   }
   else if ((water > 100) && (food > 100))
   {
      cout << "\n You collect enough food and water points to get the Four Summits Prize, pilgrim! But was it worth Lamar's life?\n";

   }
   else if ((water > 10) && (food > 10))
   {
      cout << "\nGreat job.  You get a ticket to the Vinson Massif Mountain(Locatied in Antarctica). But at what cost?\n";
   }
   else 
   {
      cout << "\nYou got juicy and tasty steak for your early arrival to the city. No prize though. And Lamar is gone.\n";
   }

   // Leave program
   exit(0);
   }


   //MOUNTAIN FUNCTIONS

   //------------------------------------------------------------
   // Purpose: To climb Mountain 
   // Input:   The water and food variables
   // Output:  None
   //------------------------------------------------------------

void Mountain1(int &water, int &food)
   {  
  
   int food_gained = 0; 
   int max_food = 3;
   int max_water = 30;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted the Kosciuszko Mountain(Highest point in Australia) \n";
   cout << "\n(You found it is harder to spell Mt kosciuszko than it is to climb it) \n";
   cout << "Food: " << food << " Water: " << water << endl;
   cout << "You climb up here was hard. The youngest of your crew is thirsty. Fortunately, there's trash everywhere.\n";
   cout << "A helicopter flies overhead. You see a plastic bottle planted in the snow.\n";
   
   water = FindWater(max_water);
   GainFood(max_food,food_gained);
   food += food_gained;
   
   cout << "\nFood: " << food << " water: " << water << endl;
   }

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain2(int &water, int &food)
   {  
   int food_gained = 0; 
   int max_water = -10;
   int max_food = 3;
  
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted the Denali Mountain (North American) \n";
   cout << "\nIt's unbelievably cold and is used as a training ground for the Himalayas) \n";


 
    
    GainFood( max_food, food_gained);
    water = FindWater(max_water);
    food += food_gained; 
    
    cout << "\nFood: " << food << " water: " << water << endl;
   }

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain3(int &water, int &food)
   {  
   
   int food_gained = 0; 
   int max_water = 10;
   int max_food = -66;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted the Aconcagua Mountain(Highest Mountain outside of the Himalayas) \n";
   cout << "\nThe peak rises almost 7000m into the air \n";

   water = FindWater(max_water);
   GainFood( max_food,  food_gained);
   food += food_gained;
 
   cout << "\nFood: " << food << " water: " << water << endl;
   }

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain4(int &water, int &food)
   {  
   
   int food_gained = 0; 
   int max_water = -100;
   int max_food = 20;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted the Everest Mountain(Highest Mountain in the world) \n";
   cout << "\nNo other mountain is so instantly recognizably or has such a history surrounding it) \n";
   
   GainFood(max_food, food_gained);
   food += food_gained;
   water = FindWater(max_water);

   cout << "\nFood: " << food << " water: " << water << endl;
   }

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain5(int &water, int &food)
   {  
   
   int food_gained = 0; 
   int max_water = 300;
   int max_food = -250;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted Stone Mountain in Atlanta, GA.\n";
   cout << "\n They're holding a Taylor Swift concert around 500 ft. below where you stand.\n";
   cout << "It appears tourists have left some salvagable trash.\n";
  
   GainFood( max_food, food_gained);
   food += food_gained;
   water = FindWater(max_water);
   
   cout << "\nFood: " << food << " water: " << water << endl;
}

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain6(int &water, int &food)
   {  
   
   int food_gained = 0; 
   int max_water = 400;
   int max_food = -800;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted Stone Mountain in Atlanta, GA.\n";
   cout << "\n They're holding a Taylor Swift concert around 500 ft. below where you stand.\n";
   cout << "It appears tourists have left some salvagable trash.\n";
   
   water = FindWater(max_water);
   GainFood(max_food, food_gained);
   food += food_gained;
   
   cout << "\nFood: " << food << " water: " << water << endl;
   }
 
//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain7(int &water, int &food)
   {
  
   int food_gained = 0;   
   int max_water = 30;
   int max_food = -100;   
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nYou just summitted Mount Sequoyah of Fayetteville, Arkansas.\n";
   cout << "\n Men or boys- what they are, you do not know- zoom past in small mopeds. Their faded polo-shirts wave like flags behind them.\n";
   cout << "It appears tourists have left some salvagable trash.\n";
   
   water = FindWater(max_water);
   GainFood( max_food, food_gained);
   food += food_gained;
   cout << "It looks like some residents were having a cookout! They give you +200 Food!\n";
   food += 200;
   cout << "\nFood: " << food << " water: " << water << endl;
   }  

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------

void Mountain8(int &water, int &food)  
   {
  
   int food_gained = 0;     
   int max_water = -30;
   int max_food = 100;
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\n The mountain is not a mountain as you would concieve of it, but rather a large cylander.\n";
   cout << "\n It appears you have summitted SPACE MOUNTAIN™ in DISNEYWORLD™, ORLANDO, FLORIDA.\n";
   cout << "It appears tourists have left some salvagable trash. You find some of those Mickey Mouse ears too.\n";
   
   

   water = FindWater(max_water);
   GainFood( max_food, food_gained);
   food += food_gained;

   cout << "\nFood: " << food << " water: " << water << endl;
}


//------------------------------------------------------------
// Purpose: To let the player know when he/she has died.
//------------------------------------------------------------

int gameover(int&partysize)
{
    if (partysize <= 0)
       {
        clearscreen(50);
        cout << "                                                 YOU ARE DEAD.\n";
        return(0);
       }
       return(partysize);
}



//------------------------------------------------------------
// Purpose: To clear the screen for scene transitions.
//------------------------------------------------------------

void clearscreen(int h)
{
    int D = 0;

    while (D <= h)
    {
    cout << " \n";
    D++;
    }
}


//------------------------------------------------------------
// Purpose: Draws the Player's Party.
//------------------------------------------------------------

void drawparty(int &partysize)

        {

		int hc =0;
//Drawing the hats.
                while (hc < partysize)
                        {
                                cout << " __∏__ ";
                                hc++;
                        }
                                cout <<endl;
                                hc =0;
//Drawing the faces.
                while (hc < partysize)
                        {
                                cout << " (•-•) ";
                                hc++;
                        }
                                cout <<endl;
                                hc =0;
//Drawing the arms.
                while (hc < partysize)
                        {
                                cout << " ===== ";
                                hc++;
                        }
                                cout <<endl;
                                hc=0;
//Drawing the feet.
                while (hc < partysize)
                        {
                                cout << " [] [] ";
                                hc++;
			}
		}
//------------------------------------------------------------
//This the introduction to the program.
//------------------------------------------------------------





//------------------------------------------------------------
//This the introduction to the program.
//------------------------------------------------------------

void intro(int &partysize)

   {

//Declaring the menu navigation variable.
   char partytemp[256];
   char mensel;

//Clearing screen.

   clearscreen(50);

//Cout statements for drawing ASCII graphics.
   cout << "                                       █████████████████████████████████████████████████████████████   \n";
   cout << "                                       █        ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.   █   \n";
   cout << "                                       █   ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒░▒░:. █   \n";
   cout << "                                       █          .                   ^                 .          █   \n";	
   cout << "                                       █ ____________▲______▲_______//▲░`_____▲___________▲___▲___ █   \n";
   cout << "                                       █ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ █   \n";
   cout << "                                       █████████████████████████████████████████████████████████████   \n";
   

//Title

   clearscreen(4);
   
   cout << "                                        Welcome to John Bunyan's Pilgrim's Progress: The Video Game\n";
   cout << "                                                          Adapted   by    Caleb Duke\n";
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                       For the best viewing experience, re-size your terminal to 146 x 30!\n";
   cout << "                                 The TWO LINES above and below this text should take up the full width of the screen.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(6);


//This is the code for choosing the size of your party.
   cout << "The goal of this game is to (A) collect as much FOOD and WATER as you can to win the hiking challenge and (B) not DIE.\n";
   cout << "Please enter your party size. The larger the party size, the larger the cost of resources. Maximum party size is 5, and the minimum is 1.\n";
   


do 
   {
   
   
   cin >> partytemp;
   partysize = atoi(partytemp);
   if ((partysize <= 0) || (partysize > 5))
   {
   cout << "Please enter a proper party size at least 1 and no more than 5.\n";     
   }
   }

   while((partysize <= 0) || (partysize > 5));

//Scene Change to party finalization.

   clearscreen(50);
   drawparty(partysize);
   clearscreen(2);

   cout << "The road winds ahead of you. You have "<< partysize << " pilgrims.\n";

   clearscreen(1);

   cout << "Do you wish to continue with this party? (Y/N)\n";

   cin >> mensel;

//If the player changes their mind about the party size, they can re-adjust.
//Nested loops are used for error checking.
if (mensel == 'N')

{
   while (mensel == 'N')
      {
         do 
        {
   
   
        cin >> partytemp;
         partysize = atoi(partytemp);
        if ((partysize <= 0) || (partysize > 5))
        {
        cout << "Please enter a proper party size at least 1 and no more than 5.\n";     
        }
        }

        while((partysize <= 0) || (partysize > 5));

         drawparty(partysize);
         clearscreen(2);
         cout << "Do you wish to continue with this party? (Y/N)\n";
         cin >> mensel;
      }
    }

    else if (mensel != 'N' && mensel != 'Y')
    {
    while (mensel != 'N' && mensel != 'Y')
    {
    cout << "Please type in 'Y' for yes or 'N' for no.\n";
    cin >> mensel;
    }
    }


   }



//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------

int main()
   {
   // Initialize game variables
   int water = 100;
   int food = 100;
   char direction;
   int partysize = 0;
   int fullparty = 0;
   
   srandom(time(NULL));
   //The intro function is called.
   intro(partysize);
   //The party at it's default size is called.
   //The +1 is for an NPC that joins the team later.

   fullparty = partysize  + 1;

   //Player makes first choice.
   
   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                          ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.          \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "To find your way to the exit of this bizarre land, you must climb the 8 mountains.\n";
   cout << "A guy named Evangelist told you.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                          _åß∂_\n";
   cout << "                                          (•o•)\n";
   cout << "                           Evangelist (played by Tom Hanks, 4-time academy award winner).\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(1);
   cout << "Evangelist: to get through this maze of mountains, you will need solve 7 riddles. But for this first journey, just go EAST.\n";
   cout << "If you lose all your pilgrims, you DIE. Game OVER. OVER. Over. (He didn't even try to do that echo thing, it was the mountains.)\n";
   cout << "Evangelist: And remeber, the Devil hates a smarty.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
   //For entering the direction.

   if (GetDirection() == 'E')
   Mountain1(water, food);
  
  //For entering the wrong direction.

    else if (direction != 'E')
     {
        clearscreen(50);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "                                                         _åß∂_    \n";
        cout << "                                                         (*o*)    \n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "                 You wandered from Evangelist's words! You get caught in a net, and he spanks you. (Yes that's in the book).\n";
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "That was weird... But he helps you back to where you started.\n";
        drawparty(partysize);
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        
        //The GetDirection function is called witha loop for error correction.
       
        while (GetDirection() != 'E')
          {
             cout << "Let's try again, just go East.\n";
             GetDirection();
          }
          Mountain1(water, food);
     }
      

   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << " 					     ███▒█▒░░:.                  . 	  ▒██▒▒▒▒▒▒░:.          \n";
   cout << "			                   ██▒▒█▒▒▒▒▒▒░:.     	                ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                 	        	            .	    	        ^	          .             \n";	
   cout << "			 		   ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "					   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "				           ███████████████████████████Chapter of the Twice██████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   clearscreen(1);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(4);
   
   cout << "Well, after finding your way through all of this garbage, you find a your first riddle on a sign:\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(2);
   
   cout << "    This letter is perhaps the most often used in the whole english alphabet. The previous sentence used it seven times.\n";
   cout << "				       Hint: Without this letter, mail by computer would... just be mail.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
   if (GetDirection() == 'E')
        {
        clearscreen(50);
        cout << "                                             ...Correct.\n";
        clearscreen(4);
        Mountain2(water, food);
        }
  
  else if (direction != 'E')
        {
        cout << "       -------------------------------█---█---█----████-------███-----█----█----█████-----------------------------------------------------\n";
        cout << "       -------------------------------█---█---█----█---█-----█---█----█---██---█----------------------------------------------------------\n";
        cout << "       -------------------------------█---█---█----████------█---█----█--█-█---█---████---------------------------------------------------\n";
        cout << "       -------------------------------█---█---█----█---█-----█---█----█-█--█---█----█-█---------------------------------------------------\n";
        cout << "       --------------------------------███-███-----█----█-----███-----██---█---██████-----------------------------------------------------\n";
        cout << "       -----------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "				   The answer was 'E'. Now you must suffer the consequences of your wrong-doing\n";
        cout << "		        One pilgrim is suddenly TAKEN by a macabre flying monster, called the VISTA FLY (VEE-STA Fly)\n";
       cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        partysize -= 1;
        
        if (partysize <= 0) 
        {
           gameover(partysize);
           return(0);
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nFood: " << food << " water: " << water << endl;
        cout << "Your party:\n";
        drawparty(partysize);
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        clearscreen(2);
        cout << "				           Your party stumbles back up to the top of Mount Kosciuszko.\n";
        //Another loop
        while (GetDirection() != 'E')
             {
             cout << "		         The youngest pilgrim, henceforth referred to as Lamar: We should go EAST. Literally, just go EAST.\n";
             
             }
       }
  
   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                          ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.          \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "                                       █████████████████████████████████████████████████████████    \n";
   cout << "                                       ████████████████████Chapter of the thrice████████████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   clearscreen(1);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "Well, after finding your way through all of this garbage, you find a your second riddle on the side of a port-a-potty:\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "				           Dutch Sett'lers, Zulu tribes, a war with the English, is no fish and fries.\n";
   cout << "                                         I am the country that begins with the direction you are seeking.\n";
   clearscreen(2);
   cout << "				           Hint: Go to wikipedia if you don't know. They have that website in this world.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
   
   if (GetDirection() == 'S')
   
        {
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "...Correct.\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        Mountain3(water, food);
        }
  
  else if (direction != 'S')
        {
        cout << "   -------------------------------█---█---█----████-------███-----█----█----█████----------------------------------------------------\n";
        cout << "   -------------------------------█---█---█----█---█-----█---█----█---██---█---------------------------------------------------------\n";
        cout << "   -------------------------------█---█---█----████------█---█----█--█-█---█----█----------------------------------------------------\n";
        cout << "   -------------------------------█---█---█----█---█-----█---█----█-█--█---█-----█---------------------------------------------------\n";
        cout << "   --------------------------------███-███-----█----█-----███-----██---█---██████----------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "				           The answer was 'S'. South Africa. Poor children.\n;";
        cout << "				       AGAIN, One pilgrim is suddenly taken by the Vista Fly (VEE-STA Fly)\n";
        partysize -= 1;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        
        if (partysize <= 0)
        {

                gameover(partysize);

        }
        
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Your party:\n";
        drawparty(partysize);
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        clearscreen(2);
        cout << "				           Your party stumbles back up to the top of the Denali Mountain.\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        while (GetDirection() != 'S')
        {
        cout << "		   The youngest pilgrim, henceforth referred to as Lamar: We should go South. Literally, just go South.\n";
        
        }
  }
  
  
 
  
   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                          ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.          \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "                                       █████████████████████████████████████████████████████████    \n";
   cout << "                                       ████████████████████Chapter of the Fourth████████████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   clearscreen(1);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(4);
   Mountain4(water, food);
   

   cout << "Well, after finding your way through all of this garbage, you find a your second riddle on the side of an electrical box:\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "There is a famous christmas song, the first letter of the blank word is the correct direction.\n";
   cout << "BLANK_ IN A  BLANK ___ BLANKLAND;\n";
   cout << "What is the BLANK? The first letter of that word will be the correct direction.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
  
   if (GetDirection() == 'W')
        {
        cout << "...Correct.\n";
        }
  
   else if (direction != 'W')
        {
        cout << "-------------------------------█---█---█----████-------███-----█----█----█████----------------------------------------------------\n";
        cout << "-------------------------------█---█---█----█---█-----█---█----█---██---█---------------------------------------------------------\n";
        cout << "-------------------------------█---█---█----████------█---█----█--█-█---█----█----------------------------------------------------\n";
        cout << "-------------------------------█---█---█----█---█-----█---█----█-█--█---█-----█---------------------------------------------------\n";
        cout << "--------------------------------███-███-----█----█-----███-----██---█---██████----------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

        cout << "The answer was 'S'. South Africa. Poor children.\n;";
        cout << "One pilgrim is suddenly taken by the Vista Fly (VEE-STA Fly)\n";
        partysize -= 1;
        
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nFood: " << food << " water: " << water << endl;
        cout << "Your party:\n";
        drawparty(partysize);
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        clearscreen(2);
         
         if (partysize <= 0)
          {
          gameover(partysize);

          }
        
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";  
        cout << "Your party of pilgrims stumbles back up to the top of the Denali Mountain.\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        
        //Continuing to the next mountain

        while (GetDirection() != 'S')
                {
                cout << "Lamar: We should go South. Literally, just go South.\n";
                
                }
        }
   

   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";  
   cout << "                                          ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.          \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "                                       █████████████████████████████████████████████████████████    \n";
   cout << "				           ████████████████████Chapter of the Fifth█████████████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";  
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n"; 
   clearscreen(4);
   cout << "Well, Okay then. Your party continues on a finds this message written on the side of a pine tree:\n";
   cout << "The riddle here is visual in nature. Use your knowledge of nomencalture, lest you loose another man to the Vista Fly.\n";
   cout << "A faint voice sings out in the distance: ♫ Ooooh Nooo, No not the Vis-ta ♫.\n";
   cout << "Hint: In the picture below, the three objects rendered below all begin with the same letter as that of the correct direction\n";
   clearscreen(1);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n"; 
   cout <<"                             |▒▒▒▒                       ▲██▒▒▒▒`                                        \n";
   cout <<"                             |X|▒▒▒▒  (•-•)        V    ▲█████▒▒▒▒`                                      \n";
   cout <<"                             |X|||▒▒▒▒ | |        >████████ █████▒▒▒▒`:.........                         \n";
   cout <<"                             |X||||X|▒▒▒▒           (An animal)                                          \n";
   cout <<"                        (A part of a house.)                                                             \n";
   cout <<"                                             ██░█░███ █------█ █░█░██▒▒                                  \n";                 
   cout <<"                                             ██░█░███▒ ██   █▒ █░█░██▒▒                                  \n";
   cout <<"                                                  ████████o█████▒▒▒                                      \n";
   cout <<"                                                  ░░░░░░░░o░░░░░▒▒▒                                      \n";
   cout <<"                                                  ████████o█████▒▒▒                                      \n";
   cout <<"                                                  ████████o█████▒▒▒                                      \n";
   cout <<"                                                       (Clothing)                                        \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n"; 
   if (GetDirection() == 'S')
         {
         cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";       
         cout << "...Correct.\n";
         cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
         Mountain5(water, food);
        }
  
  else
        {
        cout << "-------------------------------█---█---█----████-------███-----█----█----█████----------------------------------------------------\n";
        cout << "-------------------------------█---█---█----█---█-----█---█----█---██---█---------------------------------------------------------\n";
        cout << "-------------------------------█---█---█----████------█---█----█--█-█---█----█----------------------------------------------------\n";
        cout << "-------------------------------█---█---█----█---█-----█---█----█-█--█---█-----█---------------------------------------------------\n";
        cout << "--------------------------------███-███-----█----█-----███-----██---█---██████----------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "The Vista fly swoops in and bellows: You have sinned. The answer was 'S', for South.\n";
        
        clearscreen(1);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        
        cout << "Two pilgrims are suddenly taken by the Vista Fly (VEE-STA Fly). The party is shocked\n";
        partysize -= 2;
         
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    if (partysize <= 0)    
    {
        gameover(partysize);   
        return(0);
    }   
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nFood: " << food << " water: " << water << endl;
        cout << "Your party:\n";
        drawparty(partysize);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        clearscreen(2);
        cout << "Lamar: Wait! That's not even what sin is! You need to practice your theology, Vista Fly!\n";
        cout << "Lamar pulls out his slingshot of love. He picks up a nearby owl pellet and prepares to fire.\n";
        cout << "Do you want to allow him to attack the Vista fly?(Y/N)\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cin >> direction;
        if (direction == 'Y')
                { 
                        clearscreen(50);
                        cout << "Lamar aims true and strikes the beast.\n";
                        cout << "The giant moth-mosquito hybrid crashes into the snow and trash.\n";
                        clearscreen(1);
                        cout << "The Pilgrims you lost climb out of the large, furry clutches of the beast!!!\n";
                        cout << "They are a little shaken, but happy to be alive. It is an emotional moment for everyone.\n";
                        partysize = fullparty;
                }
        else
               {
               cout << "You call out to Lamar. He stops and nods. Everyone retreats.\n";
               cout << "Your party stumbles back up to the top of the Denali Mountain.\n";
               }
        while (GetDirection() != 'S')
               {
               cout << "Lamar: We should go South. Literally, just go South.\n";
               
               }
        } 
  
   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                          ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.          \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "                                       █████████████████████████████████████████████████████████    \n";
   cout << "				           ███████████████████ Chapter of the Sixth ████████████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

   clearscreen(4);
   Mountain6(water, food);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "The final riddle is written on a rock: Without this letter, we couldn't spell silver or oysters. Or sand.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
    
   if (GetDirection() != 'S')

          {
        while (GetDirection() != 'S')
          {
          cout << "Lamar: We should go South. Literally, just go South.\n";
          cout << "This time, your party is not attacked, but you lose" << partysize << "food and water due to stomach bug.\n";
          clearscreen(3);
          cout << "Lamar: GO SOUTH. The answer is S... For South. We'll die out here if we stay for too long.\n";
          water -=partysize;
          food -=partysize;
          }
          }

   clearscreen(50);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                           ███▒█▒░░:.                  .       ▒██▒▒▒▒▒▒░:.         \n";
   cout << "                                       ██▒▒█▒▒▒▒▒▒░:.                       ▒▒██▒▒▒▒▒▒▒▒▒▒░▒░:.     \n";
   cout << "                                                .                   ^                 .             \n";	
   cout << "                                       ____________▲______▲_______//`░`_____▲___________▲___▲___    \n";
   cout << "                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒    \n";
   cout << "                                       █████████████████████████████████████████████████████████    \n";
   cout << "                                       ███████████████████ Chapter of the Seventh ██████████████    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   clearscreen(1);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

   clearscreen(2);
   Mountain7(water, food);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                                         _                                                              \n";
   cout << "                                        |█|                                                             \n";
   cout << "                          ◊          |███████|                                                          \n";
   cout << "                          | __█__       |█|                                                             \n";
   cout << "                          |_(•-•)       |█|                                                             \n";
   cout << "                          |  | |        |█|                                                             \n";
   cout << "          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                              \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(2);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "                 You see another pilgrim from the Town of destruction: He makes his way through the suburban streets to a cross.\n";
   cout << "                     His burden falls off.\n";
   cout << "Lamar: Hey man! I'm glad you were able to get that thing off! Do you know which way we need to go from here?.\n";
   
   clearscreen(1);
   
   cout << "Pilgrim: Thine men ought turn towards the East from here. For the sun doth rise there and I see the city.\n";
   cout << "The pilgrim joins your ranks!\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
   if (GetDirection() == 'E')
      {
        cout << "...Correct.\n";
   
      }

   else if (direction != 'E')

      {
           cout << "The new pilgrim: I have doth spoken the correct way: East.\n";
           while (GetDirection() != 'E')
           {
                   cout << "Pilgrim: Tryeth again.\n";
                   

           }
     }

clearscreen(50);
cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒||||||||||||▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ▒▒▒▒▒░░░░░   ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ▒▒Disney™░   ░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒░░ ▒▒World  ░   ░░░░░░░░░░░░░▒▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒▒▒▒░░░░░░ ▒▒∏▒∏▒∏░∏░   ░░░░░░░░░░░░░░▒▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒▒▒▒░░░░░░░░░ ▒▒▒▒▒░░░░░   ░░░░░░░░░░░░░░░▒▒▒▒▒▒|    \n";
cout << "                                        |▒▒▒░░░░░░░░░░░░ ▒▒▒▒▒◊░░░░   ░░░░░░░░░░░░░░░░▒▒▒▒▒|    \n";
cout << "                                        |▒░░░░░░░░░░░░░░ ▒▒▒▒( )░░░   ░░░░░░░░░░░░░░░░▒▒▒▒▒|    \n";
cout << "                                        |██████████████████The final Stand ████████████████|    \n";
cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   clearscreen(1);
   cout << "You reach the base of the mountain... You hear the music of the Celestial city on the other side...\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   Mountain8(water, food);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";   
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";   
   cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ▒▒▒▒ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ▒▒░░     ░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ▒░░  ˚∞˚  ░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ░░░░    ░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒▒▒▒▒▒▒▒░░ ░    |||    ░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒▒▒▒░░░░░░  ░░  ░░  ░ ░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒▒▒▒░░░░░░░░░ ░░░      ░ ░░░░░░░░░░░░░░░░░▒▒▒▒▒▒|    \n";
   cout << "                                        |▒▒▒░░░░░░░░░░░░ ░░ ░░░░░ ░ ░░░░░░░░░░░░░░░░░░▒▒▒▒▒|    \n";
   cout << "                                        |▒░░░░░░░░░░░░░░ ░░░ ░░░░ ░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒|    \n";
   cout << "                                        |██████████████████The final Stand part II ████████|    \n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << "Your party:\n";
   drawparty(partysize);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   clearscreen(1);
   cout << "Now POLEON; the prince of EVIL himself, appears. He has two mouths, on his reptillian-like head, and the other on his belly.\n";
   cout << "He wispers a few words to you and your party: SSSSSTOPPPPP BEFOOOORE YOU DIEEEEE.\n";
   clearscreen(2);
   cout << "A Peter Jackson-esque fight scene happens. It looks like a cross over of a Thanksgiving festival and a Magic the Gathering card.\n";
   cout << "However, the fight turns to Poleon's favor.\n";
   cout << "The belly-mouth starts breathing fire and slime. It gapes open.\n";
   cout << "Lamar: We need to through some of this random food we've found at that BELLY-MOUTH. He's bound to be allergic to something!\n";
   cout << "Would you like to (A) throw ALL the food you have collected at your enemy, or (B) keep the food and run AROUND the mountain.\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   //A modified version of the navigation loop.
   
   while ((direction != 'A') && (direction != 'B'))
   { 
      cout << "Enter A or B.\n";
      cin >> direction;
   }
   
   if (direction == 'A')
        
     {  
        clearscreen(50);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Your group of wounded pilgrims hold hands and say grace... And then proceed to throw food at speeds unseen before\n";
        cout << "Johnny Cash's 'Hurt'- a great song by the way- plays in the background:\n";
        cout << "♫ What have I become.... My sweetest friend.... ♫\n";
        cout << "A flash of light engulfs Poleon as he is hit by left-over pop-tarts and kale. But he was killed by pack of smarties. Thrown by you...\n";
        clearscreen(2);
        cout << "... A pack of smarties.\n";
        food = 0;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
     }

     else if (direction == 'B')

     {
             cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
             cout << "Everyone scrams to the exit, but you lose Lamar, who saved one of the pilgrims from getting hit in the back with an arrow, taking the arrow himself.\n";
             cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
     }
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "\nFood: " << food << " water: " << water << endl;
   cout << " The Challenge has now been complete. You have escaped the mountains. The Judges boom in a loud voice:\n";
   Exit(water, food);
   cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
   
   if (direction == 'A')
        {
             cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";   
             cout << "But none of that matters. The pilgrims go to the celestial city. Safe and sound, and as brothers after such a trial.\n";
             clearscreen(3);
             cout << "                                      The. End.\n";
             cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
   }

   
