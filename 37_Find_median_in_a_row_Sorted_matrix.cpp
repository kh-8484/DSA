class Solution {
public:
	int median(vector<vector<int>> &matrix, int r, int c) {
		// code here
		int k = ( r * c + 1 ) / 2 ;

		int a = INT_MAX ;
		int b = INT_MIN ;

		for ( int i = 0 ; i < r ; i++ )
		{
			a = min( a , matrix[i][0] ) ;
			b = max( b , matrix[i][c - 1] ) ;
		}

		while ( a < b )
		{
			int m = ( a + b ) / 2 ;

			int cnt = 0 ;

			for ( int i = 0 ; i < r ; i++ )
				cnt = cnt + ( upper_bound( matrix[i].begin() , matrix[i].end() , m ) - matrix[i].begin() ) ;

			if ( cnt < k )a = m + 1 ;
			else b = m ;
		}

		return a ;
	}
};