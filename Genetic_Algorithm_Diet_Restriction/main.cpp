#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

const int CAL = 1350; //the more total of meal close to this value, the more accurate
const int GENE = 17; //how many meal per chromosome
const int POP_SIZE = 36; //there's 8 chromosome
const float CO_probability = 1.0;
const float MUT_probability = 0.1;
const int MAX_GENERATION = 50;

int meal[POP_SIZE][GENE]; //array for meal chromosome
double div_fit[POP_SIZE];
int parents[2][GENE]; //array to store parents
int children[2][GENE];
int newChromosome[POP_SIZE][GENE];
int newChromoCounter=0;

double bestFitness= 99.9;
double avgFitness = 0.0;
int bestChromosome[GENE];

ofstream bestFitnessFile,avgFitnessFile,bestChromosomeFile;

void initializePopulation(){

       srand (time(NULL));
       for(int c = 0; c<POP_SIZE; c++){
       meal[c][0] = rand() % (22-1) + 1;
       meal[c][1] = rand() % (95-33) + 33;
       meal[c][2] = rand() % (135-114) + 114;
       meal[c][3] = rand() % (114-33) + 33;
       meal[c][4] = rand() % (147-135) + 135;
       meal[c][5] = rand() % (159-147) + 147;
       meal[c][6] = rand() % (200-159) + 159;
       meal[c][7] = rand() % (200-159) + 159;
       meal[c][8]  = rand() % (295-200) + 200;
       meal[c][9]  = rand() % (33-22) + 22;
       meal[c][10]  = rand() % (33-1) + 1;
       meal[c][11]  = rand() % (135-114) + 114;
       meal[c][12]  = rand() % (147-135) + 135;
       meal[c][13]  = rand() % (159-147) + 147;
       meal[c][14]  = rand() % (200-159) + 159;
       meal[c][15]  = rand() % (295-200) + 200;
       meal[c][16]  = rand() % (114-33) + 33;
       }

}

void printChromosome(){
    for(int c=0; c<POP_SIZE; c++){
        cout<<"\tc"<<c<<"\t";
        for(int i = 0; i<GENE; i++){
            cout<<meal[c][i]<<" ";
        }
        cout<<endl;
    }

}

void evaluateChromosome(){
int sum=0;
double fitness = 0;
//double div_fit=0;

for(int c = 0; c < POP_SIZE; c++){
        sum = 0;
   for(int i=0; i<GENE; i++){
            sum+=meal[c][i];

        }
    cout<<"Total weight for chromosome "<<c+1<< " = "<<sum<<endl;//total weight for each population
    if(sum<CAL){
        fitness  = abs(CAL - sum);
        div_fit[c] = fitness/(double)CAL;
    }
    else{
        fitness  = abs(sum-CAL);
        div_fit[c] = fitness/(double)CAL;
    }

    cout << "Fitness of chromo " << c+1<<" = " << div_fit[c] <<endl;
}
}

void parentSelection(){
int player1, player2;
int indexParents[2];

for(int i=0; i<2; i++){
    player1 = rand() % POP_SIZE;
    do{
        player2 = rand() % POP_SIZE;
    }while(player1==player2);

    cout<<"\n\tPlayer 1 index: "<<player1;
    cout<<"\n\tPlayer 2 index: "<<player2;
    if (div_fit[player1]>div_fit[player2])
           indexParents[i]=player2;
        else
            indexParents[i]=player2;

        cout<<"\n\tIndex Parents: "<<indexParents[i];
}
for (int i=0; i<2; i++){
        cout<<"\n\tParents "<<i+1<<" : ";
    for (int g=0; g<GENE; g++){ //column
        parents[i][g] = meal[indexParents[i]][g];
        cout<<parents[i][g]<<" ";

    }
}
cout<<""<<endl;
}

void crossover(){
    float prob = 0.0;
    int co_point;

    for (int p=0; p<2; p++){//Copy parents to children
        for (int g=0; g<GENE; g++){
            children[p][g] = parents[p][g];
        }
    }
    //generate 0-1
    prob = ((rand() % 10)+1)/10.0;
    if (prob < CO_probability){//crossover happen
        co_point = rand() % GENE;
        cout << "\n\t Children crossover at " << co_point;
        for (int g=co_point;g<GENE;g++ ){
            children[0][g] = parents[1][g];
            children[1][g] = parents[0][g];
        }
    }
    else{//crossover did not happen
            cout << "\n\t Crossover did not happen " ;
    }
    //output
       for (int c=0; c<2; c++){
            cout << "\n\t Children " << c+1 << " : " ;
        for (int g=0; g<GENE; g++){
            cout << children[c][g] << " ";
        }
    }
}

void mutation(){
     //srand (time(NULL));
     int randValue, mutationBit;
     for (int i=0; i<2; i++){
        randValue =(rand()%10)/10.0;
        if (randValue<MUT_probability){
           mutationBit = rand() % GENE;
           cout<<"\n\t Mutation bit: " <<mutationBit;
           if(mutationBit==0)
            {
            children[i][mutationBit]=rand() % (22-1) + 1;
           }
           else if(mutationBit==1)
           {
            children[i][mutationBit]=rand() % (95-33) + 33;
           }
           else if(mutationBit==2)
            {
            children[i][mutationBit]=rand() % (135-114) + 114;
           }
           else if(mutationBit==3)
            {
            children[i][mutationBit]=rand() % (114-33) + 33;
           }
           else if(mutationBit==4)
            {
            children[i][mutationBit]=rand() % (147-135) + 135;
           }
           else if(mutationBit==5)
            {
            children[i][mutationBit]=rand() % (159-147) + 147;
           }
           else if(mutationBit==6)
            {
            children[i][mutationBit]=rand() % (200-159) + 159;
           }
           else if(mutationBit==7)
            {
            children[i][mutationBit]=rand() % (200-159) + 159;
           }
           else if(mutationBit==8)
            {
            children[i][mutationBit]=rand() % (295-200) + 200;
           }
           else if(mutationBit==9)
            {
            children[i][mutationBit]=rand() % (33-22) + 22;
           }
           else if(mutationBit==10)
            {
            children[i][mutationBit]=rand() % (33-1) + 1;
           }
           else if(mutationBit==11)
            {
            children[i][mutationBit]=rand() % (135-114) + 114;
           }
           else if(mutationBit==12)
            {
            children[i][mutationBit]=rand() % (147-135) + 135;
           }
           else if(mutationBit==13)
            {
            children[i][mutationBit]=rand() % (159-147) + 147;
           }
           else if(mutationBit==14)
            {
            children[i][mutationBit]=rand() % (200-159) + 159;
           }
           else if(mutationBit==15)
            {
            children[i][mutationBit]=rand() % (295-200) + 200;
           }
           else if(mutationBit==16)
            {
            children[i][mutationBit]=rand() % (114-33) + 33;
           }

        }
     }

      for (int row=0; row<2; row++){
        cout<<"\n\t Children after mutation "<<row+1<<": ";
        for(int col=0; col<GENE; col++){
            cout<<children[row][col]<< " ";
        }
    }
}


void survivalSelection(){

    for (int c=0; c<2; c++){//copy children to newChromosome
        for (int g=0; g<GENE; g++){
            newChromosome[newChromoCounter][g]=children[c][g];
        }
        newChromoCounter++;

    }
    //print the new chromosome
     for (int c=0; c<newChromoCounter; c++){
            cout << "\n\t New chromosome " << c+1 << "  : " ;
            for (int g=0; g<GENE; g++){
                cout << newChromosome[c][g] << " ";
            }
       }
}

void copyChromosome(){
     for (int c=0; c<POP_SIZE; c++){//copy newChromosome to chromosome
        for (int g=0; g<GENE; g++){
            meal[c][g]=newChromosome[c][g];
        }
    }
}

void recordBestFitness(){

    for (int c=0;c<POP_SIZE;c++){
        if(bestFitness>div_fit[c]){
            bestFitness=div_fit[c];
            for(int g =0;g<GENE;g++){
                bestChromosome[g] = meal[c][g];
            }
        }
    }
    cout <<"\nBest Fitness = "<<bestFitness;
    cout <<"\nBest Chromosome = ";
    for(int g=0 ;g<GENE;g++){
        cout<<bestChromosome[g]<<" ";
    }
    cout << endl;

    bestFitnessFile << bestFitness << endl;
    for(int g =0 ; g < GENE; g++){
        bestChromosomeFile<<bestChromosome[g]<<" ";
    }
    bestChromosomeFile<<endl;

}
void calcAvgFitness(){

    double sum=0.0;

    for (int c=0; c<POP_SIZE;c++){
    sum +=div_fit[c];
    }
    avgFitness = sum/POP_SIZE;
    cout <<"\n Average Fitness = " << avgFitness;
    avgFitnessFile << avgFitness<<endl;
    }

int main () {
    bestFitnessFile.open("besFitness.txt");
    avgFitnessFile.open("avgFitness.txt");
    bestChromosomeFile.open("bestChromosome.txt");

	cout <<"\nGA START! \n";
	cout <<"\nINITIALIZATION... \n";
	initializePopulation();
	getchar();
	for (int g=0; g<MAX_GENERATION; g++){//start of generation
        cout <<"GENERATION " << g+1 <<endl;
        cout <<"\nPRINT POPULATION \n";
        printChromosome();
        getchar();
        cout <<"\nEVALUATE CHROMOSOME \n";
        evaluateChromosome();
        recordBestFitness();
        calcAvgFitness();
        newChromoCounter=0;
        getchar();
        for (int i=0; i<POP_SIZE/2; i++){
            cout <<"\nPARENT SELECTION \n";
            parentSelection();
            cout <<"\nCROSSOVER \n";
            crossover();
            cout <<"\nMUTATION \n";
            mutation();
            cout <<"\nSURVIVAL SELECTION \n";
            survivalSelection();
        }//for creating new chromo
          cout <<"\nNEW CHROMOSOMES COPIED TO CHROMOSOME \n";
        copyChromosome();
        getchar();
	}//generation

	bestFitnessFile.close();
    avgFitnessFile.close();
    bestChromosomeFile.close();
}
