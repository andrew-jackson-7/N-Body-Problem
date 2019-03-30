//
//  Main.cpp
//  
//
//  Created by Andrew Jackson on 5/6/15.
//
//

#include "Many_Body_Problem.h"

int main(int argc, char** argv)
{
    std::cout << "test" << std::endl;
    std::ifstream dataIn("Initial_Conditions_of_Bodies_3.txt");
    if(!dataIn.is_open())
    {
        std::cout << "There is a problem opening the dataIn file." << std::endl;
    }
    
    long double G = 1.0;//(6.67384 * pow(10,-11)) Change G back when you want to, I used this value for 3 Body example.
    long double change_in_time;
    long double tracking_time = 0;
    int datapoints;
    
    std::cout << "Please enter a numerical value for the change in time used for numerical calculations." << std::endl;
    
    std::cin >> change_in_time;
    
    std::cout << "Please enter a numerical value for the number of datapoints used for numerical calculations." << std::endl;
    
    std::cin >> datapoints;
    
    int count = 0;
    int newcount = 0;
    std::istringstream char_element;
    std::string store;
    
    while (getline(dataIn, store))//counting the number of params in textfile
    {
        char_element.str(store);
        while (char_element >> store)
        {
            count++;
        }
        char_element.clear();
        char_element.seekg(0,char_element.beg);
    }
    
    double* String_Params = new double[count];
    dataIn.clear();
    dataIn.seekg(0,dataIn.beg);
    
    char_element.clear();
    char_element.seekg(0,char_element.beg);
    
    double Result;
    
    while (getline(dataIn, store))
    {
        char_element.str(store);
        while (char_element >> store)
        {
            std::stringstream convert(store);
            convert >> Result;
            String_Params[newcount] = Result;
            std::cout << String_Params[newcount] << std::endl;
            newcount++;
        }
        char_element.clear();
        char_element.seekg(0,char_element.beg);
        
    }
    
    int N = count/7;
    std::cout << "This is N: " << N << std::endl;
    int j = 1;
    
    Body** Pointer_Body_Array = new Body*[N];
    for (int i = 1; i <= N; i++)
    {
        Pointer_Body_Array[i-1] = (new Body(String_Params[(i - 1) * 7 + (j - 1)], String_Params[(i - 1) * 7 + (j)], String_Params[(i - 1) * 7 + (j + 1)], String_Params[(i - 1) * 7 + (j + 2)], String_Params[(i - 1) * 7 + (j + 3)], String_Params[(i - 1) * 7 + (j + 4)], String_Params[(i - 1) * 7 + (j + 5)]));
    }
    std::cout << Pointer_Body_Array[0] -> get_position_x() << std::endl;
    std::cout << Pointer_Body_Array[0] -> get_velocity_x() << std::endl;
    
    long double* temp_velocity_x = new long double[N];
    long double* temp_position_x = new long double[N];
    long double* temp_velocity_y = new long double[N];
    long double* temp_position_y = new long double[N];
    long double* temp_velocity_z = new long double[N];
    long double* temp_position_z = new long double[N];
    
    std::ofstream dataOut("Evolving_Values.txt");
    
    for (int i = 1; i <= N; i++)
    {
        dataOut << tracking_time << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_velocity_x() << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_velocity_y() << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_velocity_z() << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_position_x() << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_position_y() << " ";
        dataOut << Pointer_Body_Array[i-1] -> get_position_z() << std::endl;
    }
    
    long double Summed_Force_Term_x = 0;
    long double Summed_Force_Term_y = 0;
    long double Summed_Force_Term_z = 0;
    
    for (int k = 1; k < datapoints; k++)
    {
        tracking_time = change_in_time + tracking_time;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i != j)
                {
                    //This loop is to calculate the net acceleration on the object of interest, I accidently called the summing variable a force, its not.
                    Summed_Force_Term_x = Summed_Force_Term_x + (Pointer_Body_Array[i-1] -> Acceleration_x(G, (Pointer_Body_Array[j-1] -> get_position_x()), (Pointer_Body_Array[j-1] -> get_position_y()), (Pointer_Body_Array[j-1] -> get_position_z()), (Pointer_Body_Array[j-1] -> get_mass())));
                    
                    Summed_Force_Term_y = Summed_Force_Term_y + (Pointer_Body_Array[i-1] -> Acceleration_y(G, (Pointer_Body_Array[j-1] -> get_position_x()), (Pointer_Body_Array[j-1] -> get_position_y()), (Pointer_Body_Array[j-1] -> get_position_z()), (Pointer_Body_Array[j-1] -> get_mass())));
                    
                    Summed_Force_Term_z = Summed_Force_Term_z + (Pointer_Body_Array[i-1] -> Acceleration_z(G, (Pointer_Body_Array[j-1] -> get_position_x()), (Pointer_Body_Array[j-1] -> get_position_y()), (Pointer_Body_Array[j-1] -> get_position_z()), (Pointer_Body_Array[j-1] -> get_mass())));
                }
            }
            dataOut << tracking_time << " ";
            
            dataOut << (Pointer_Body_Array[i-1] -> Num_Velocity_x(Summed_Force_Term_x, change_in_time)) << " ";
            dataOut << (Pointer_Body_Array[i-1] -> Num_Velocity_y(Summed_Force_Term_y, change_in_time)) << " ";
            dataOut << (Pointer_Body_Array[i-1] -> Num_Velocity_z(Summed_Force_Term_z, change_in_time)) << " ";
            
            temp_velocity_x[i-1] = (Pointer_Body_Array[i-1] -> Num_Velocity_x(Summed_Force_Term_x, change_in_time));
            temp_velocity_y[i-1] = (Pointer_Body_Array[i-1] -> Num_Velocity_y(Summed_Force_Term_y, change_in_time));
            temp_velocity_z[i-1] = (Pointer_Body_Array[i-1] -> Num_Velocity_z(Summed_Force_Term_z, change_in_time));
            
            dataOut << Pointer_Body_Array[i-1] -> Num_Position_x(change_in_time) << " ";
            dataOut << Pointer_Body_Array[i-1] -> Num_Position_y(change_in_time) << " ";
            dataOut << Pointer_Body_Array[i-1] -> Num_Position_z(change_in_time) << std::endl;
            
            temp_position_x[i-1] = Pointer_Body_Array[i-1] -> Num_Position_x(change_in_time);
            temp_position_y[i-1] = Pointer_Body_Array[i-1] -> Num_Position_y(change_in_time);
            temp_position_z[i-1] = Pointer_Body_Array[i-1] -> Num_Position_z(change_in_time);
            Summed_Force_Term_x = 0;
            Summed_Force_Term_y = 0;
            Summed_Force_Term_z = 0;
        }
        for (int i = 1; i <= N; i++)
        {
            (Pointer_Body_Array[i-1] -> set_velocity_x(temp_velocity_x[i-1]));
            (Pointer_Body_Array[i-1] -> set_position_x(temp_position_x[i-1]));
            (Pointer_Body_Array[i-1] -> set_velocity_y(temp_velocity_y[i-1]));
            (Pointer_Body_Array[i-1] -> set_position_y(temp_position_y[i-1]));
            (Pointer_Body_Array[i-1] -> set_velocity_z(temp_velocity_z[i-1]));
            (Pointer_Body_Array[i-1] -> set_position_z(temp_position_z[i-1]));
        }
    }
    dataIn.clear();
    dataIn.close();
    dataOut.clear();
    dataOut.close();
}
    

