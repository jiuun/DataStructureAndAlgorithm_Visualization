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

#include "ArrayList.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
    vector<int> arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    vector<int> arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    vector<int> arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };


    arr1 = { 6, 2, 5, 7, 3, 8, 7, 1, 9, 4 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    //sort::BubbleSort::Sort(arr1);
    //sort::BubbleSort::Sort(arr2);

    //sort::BubbleSortVisualizer::VisualizeSorting(arr1, eViewMode::SEQUENCE, eDebug::ON);
    //sort::BubbleSortVisualizer::VisualizeSorting(arr2, eViewMode::ONE_BY_ONE, eDebug::OFF);
    //sort::BubbleSortVisualizer::VisualizeSorting(arr3, eViewMode::SEQUENCE, eDebug::OFF);

    arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };


    //sort::SelectionSort::Sort(arr1);
    //sort::SelectionSort::Sort(arr2);

    //sort::SelectionSortVisualizer::VisualizeSorting(arr1, eViewMode::SEQUENCE, eDebug::ON);
    //sort::SelectionSortVisualizer::VisualizeSorting(arr2, eViewMode::ONE_BY_ONE, eDebug::OFF);
    //sort::SelectionSortVisualizer::VisualizeSorting(arr3, eViewMode::SEQUENCE, eDebug::OFF);

    arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    //sort::InsertionSort::Sort(arr1);
    //sort::InsertionSort::Sort(arr2);

    //sort::InsertionSortVisualizer::VisualizeSorting(arr1, eViewMode::SEQUENCE, eDebug::OFF);
    //sort::InsertionSortVisualizer::VisualizeSorting(arr2, eViewMode::SEQUENCE, eDebug::OFF);
    //sort::InsertionSortVisualizer::VisualizeSorting(arr3, eViewMode::SEQUENCE, eDebug::OFF);
    

    arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    //sort::QuickSort::Sort(arr1);

    //sort::QuickSortVisualizer::VisualizeSorting(arr1, ePivotPos::RIGHT, eViewMode::SEQUENCE, eDebug::OFF);
    //sort::QuickSortVisualizer::VisualizeSorting(arr2, ePivotPos::RIGHT, eViewMode::ONE_BY_ONE, eDebug::OFF);
    //sort::QuickSortVisualizer::VisualizeSorting(arr3, ePivotPos::RIGHT, eViewMode::SEQUENCE, eDebug::OFF);
    

    arr1 = { 7, 2, 5, 1, 3, 8, 7, 4, 9, 6 };
    arr2 = { 4, 2, 5, 1, 6, 7, 3, 8, 1,  3, 8, 7, 4, 9, 1, 5, 3, 8, 9, 6 };
    arr3 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    //sort::QuickSortVisualizer::VisualizeSorting(arr1, ePivotPos::LEFT, eViewMode::ONE_BY_ONE, eDebug::OFF);
    //sort::QuickSortVisualizer::VisualizeSorting(arr2, ePivotPos::LEFT, eViewMode::SEQUENCE, eDebug::OFF);
    //sort::QuickSortVisualizer::VisualizeSorting(arr3, ePivotPos::LEFT, eViewMode::SEQUENCE, eDebug::OFF);

#ifdef _DEBUG
    {
        linear::ArrayList::Test();
        linear::Queue::Test();
        linear::Stack::Test();
    }
#endif
}
