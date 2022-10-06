#include <iostream>
#include <Windows.h>

#include "BubbleSort.h"
#include "BubbleSortVisualizer.h"
#include "InsertionSort.h"
#include "InsertionSortVisualizer.h"
#include "SelectionSort.h"
#include "SelectionSortVisualizer.h"
#include "QuickSort.h"
#include "QuickSortVisualizer.h"


int main()
{
    vector<int> arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    vector<int> arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };

    //sort::QuickSort::Sort(arr1);

    sort::QuickSortVisualizer::VisualizeSorting(arr1, ePivotPos::RIGHT, eViewMode::SEQUENCE);
    sort::QuickSortVisualizer::VisualizeSorting(arr2, ePivotPos::RIGHT, eViewMode::ONE_BY_ONE);

    arr1 = { 6, 2, 5, 7, 3, 8, 7, 1, 9, 4 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };

    sort::QuickSortVisualizer::VisualizeSorting(arr1, ePivotPos::LEFT, eViewMode::ONE_BY_ONE);
    sort::QuickSortVisualizer::VisualizeSorting(arr2, ePivotPos::LEFT, eViewMode::SEQUENCE);

    arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };


    //sort::BubbleSort::Sort(arr1);
    //sort::BubbleSort::Sort(arr2);

    //sort::SelectionSort::Sort(arr1);
    //sort::SelectionSort::Sort(arr2);

    sort::InsertionSort::Sort(arr1);
    sort::InsertionSort::Sort(arr2);
}
