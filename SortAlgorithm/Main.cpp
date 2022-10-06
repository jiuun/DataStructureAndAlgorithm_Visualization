#include <iostream>
#include "QuickSort.h"
#include "QuickSortVisualizer.h"

#include <Windows.h>

int main()
{
    vector<int> arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };

    //sort::QuickSort::Sort(arr1);

    sort::QuickSortVisualizer visualizer;
    visualizer.VisualizeSorting(arr1);
}
