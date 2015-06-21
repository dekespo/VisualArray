#ifndef __VISUALARRAY_H__
#define __VISUALARRAY_H__

#include <vector>
#include <deque>
#include <iostream>

// Temporary color
struct Color { int i; };

enum HISTORY_TYPE { SET, SWAP, COLOR, DECOLOR, HIGHLIGHT, SEPARATE, DESEPARATE };

class VisualArray;

//template<typename T>
class VisualArrayData {
public:
	VisualArrayData();
	VisualArrayData(int _pos, VisualArray* _parent);
	//operator int();
	
	// usual arithmetical operations
	// comparator operations between itself and int
	// add any extra friend functions between this class and int
private:
	int data;
	int pos;
	VisualArray* parent;
};

//template<class T>
struct VisualArrayHistory {
	HISTORY_TYPE type;
	int pos, pos2;
	int data;
	float size;
	Color color;
};

//template<class T>
class VisualArray {
public:
	VisualArray(int size);
	~VisualArray();

	//VisualArrayData operator [](int i) const;
	//VisualArrayData& operator [](const int i);
	int operator [](int i) const;
	int& operator [](const int i);

	void addSetEvent(int pos, int data);
	void gfxHighlight(int index, Color);
	void gfxColor(int index, Color);
	void gfxDecolor(int index);
	void gfxSeparate(int leftindex, float size, Color);
	void gfxDeseparate(int leftindex);
	void hideLastOperation();
	void clearHistory();
	void render();

private:
	VisualArrayHistory nextOperation();
	void renderNext();

	bool mGraphicsReady;
	int mSize;
	int *mData, *mOriginal;
	//VisualArrayData *mData;
	//VisualArrayData *mOriginal;
	std::deque< VisualArrayHistory > mHistory;
	std::vector<int> mRectangles;
	std::vector<int> mLastHighlights;

	Color gfxDefaultColor, gfxDefaultHighlightColor, gfxDefaultSeparatorColor;
};

#endif