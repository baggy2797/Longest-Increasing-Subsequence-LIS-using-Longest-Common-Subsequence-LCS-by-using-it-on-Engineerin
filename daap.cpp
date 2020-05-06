#include<iostream>
using namespace std; 

// Define the Structure
struct Pairs
{
    //north and south coordinates of the city
	int north, south; 
}; 

// returns max
bool compare(struct Pairs a, struct Pairs b)
{ 
	if (a.south == b.south) 
		return a.north < b.north; 
	return a.south < b.south; 
} 

// to find the maximum bridges to be built
int maxBridges(struct Pairs values_pairs[], int n)
{ 
	int lcs[n];
	for (int i=0; i<n; i++) 
		lcs[i] = 1;
		
    // Logic of Longest Common Subsequence applied to the Numbers //
    
	sort(values_pairs, values_pairs+n, compare);
	
	
	for (int i=1; i<n; i++) 
		for (int j=0; j<i; j++) 
			if (values_pairs[i].north >= values_pairs[j].north && lcs[i] < 1 + lcs[j])
				lcs[i] = 1 + lcs[j];
	
		
	int max = lcs[0];
	for (int i=1; i<n; i++) 
		if (max < lcs[i])
			max = lcs[i];
	

    cout<<"Lcs's using Lis's are :\n";
    
    
	 
	return max;
    // rteurns the Maximum value of the # of Bridges
} 

int main() 
{ 
    int n = 0; 
	struct Pairs values_pairs[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};

    cout<<"Enter the Number of cities you wish to consider : \n";
    cin>>n;
	
    cout << "Please enter "<<n<<" values of north-south pairs: \n";
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the North Coordinate value \n";
        cin >> values_pairs[i].north;
        cout<<"Enter the South Coordinate value \n";
        cin >> values_pairs[i].south;
        
        cout<<"North Value = "<< values_pairs[i].north<<"\t"<<"South Value = "<<values_pairs[i].south<<"\n";
    }

    int new1 = maxBridges(values_pairs, n);
	cout << "Maximum number of bridges = "<<new1<<"\n";
    	 
	return 0; 
} 
