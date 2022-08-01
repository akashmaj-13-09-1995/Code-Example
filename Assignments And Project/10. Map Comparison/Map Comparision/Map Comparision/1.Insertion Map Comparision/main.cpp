#include <iostream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>

#include <chrono>

#include "pbPlots.h"
#include "supportLib.h"



using namespace std;

int main(int argc, char** argv)
{

    int num;
    cout<<"Enter the Number of points:";
    cin>>num;
    using namespace std::chrono;

    RGBABitmapImageReference *imageRef1 = CreateRGBABitmapImageReference();
    StringReference *str1 = new StringReference();

    RGBABitmapImageReference *imageRef2 = CreateRGBABitmapImageReference();
    StringReference *str2 = new StringReference();

    vector<double> x1;
    vector<double> y1;

    vector<double> x2;
    vector<double> y2;






    time_t t;
    struct tm * tt;
    time(&t);
    tt = localtime(&t);
   // cout << "Current Day, Date and Time is = " << t << " " << asctime(tt);

    std::map<int, int> order;
    uint64_t intialTime, before, after, finalTime;
    //    time(&intialTime);
    intialTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    for (int x = 0; x < num+1; x++)
    {
        before = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        order.insert({x, rand()});
        after = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

        finalTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        cout << "( " << x + 1 << " , " << (after - before) << " )" << endl;

        x1.push_back(x + 1);
	 // x1.push_back((finalTime-intialTime)/1000);
        if ( (after - before) > 1000 )
            y1.push_back((after - before)%1000);
        else
            y1.push_back(after - before);

    }

    unordered_map<int, int> umap;
    intialTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

    for (int x = 0; x < num+1; x++)
    {
        before = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        umap.insert({x, rand()});
        after = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

        finalTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        cout << "( " << x + 1 << " , " << (after - before) << " )" << endl;

        x2.push_back(x + 1);
	 // x2.push_back((finalTime-intialTime)/1000);
         if ( (after - before) > 1000 )
            y2.push_back((after - before)%1000);
        else
            y2.push_back(after - before);
    }

    x1.erase(x1.begin());
    x2.erase(x2.begin());
    y1.erase(y1.begin());
    y2.erase(y2.begin());

    DrawScatterPlot(imageRef1, 600, 400, &x1, &y1, str1);
    DrawScatterPlot(imageRef2, 600, 400, &x2, &y2, str2);

    vector<double> *pngData1 = ConvertToPNG(imageRef1->image);
    WriteToFile(pngData1, "Orderd_Map.png");
    DeleteImage(imageRef1->image);

    vector<double> *pngData2 = ConvertToPNG(imageRef2->image);
    WriteToFile(pngData2, "Unordered_Map.png");
    DeleteImage(imageRef2->image);


    return 0;

}

