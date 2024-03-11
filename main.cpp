#include<iostream>
#include<vector>
using namespace std;
const char WALL = '|';
const char OPEN_SPACE = '*';
const char PATH = '@';
const char START = 'S';
const char END = 'E';

class Maze{
    private: 
    int size;
    int wallper;
    vector<vector<char>>maze;
    public: 
    Maze(int size,int wallper)
    {
        this->size=size;
        this->wallper= wallper;
        maze = vector<vector<char>>(size,vector<char>(size,WALL));
    }   
    void Generator(){
        for(int i =0;i<size;i++)
        {
            for(int j =0;j<size;j++)
            {
                if(rand()%100>wallper)
                {
                    maze[i][j]  = OPEN_SPACE;
                }

            }
        }
        maze[0][0]=START;
        maze[size-1][size-1]=END;
    } 
    void PrintMaze()
    {
        for(auto &row : maze){
            for(auto &col : row){
                cout << col ;
        }
        cout<<endl;
    }
    
}
const vector<vector<char>>&getMaze() const{
        return maze;
    }
};
int main()
{
    int size, wallper;
    cout<<"Enter Size of the maze: ";
    cin>>size;
    cout<<"Enter Wall Percentage: ";
    cin>>wallper;
    Maze genMaze(size,wallper);
    genMaze.Generator();
    genMaze.PrintMaze();
    return 0;
}
/*

*/