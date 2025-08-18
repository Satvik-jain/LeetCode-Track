class StockSpanner {
public:
    stack<pair<int,int>> st;  // {price, span}

    StockSpanner() {
        // stack starts empty, nothing else required
    }
    
    int next(int price) {
        int span = 1;
        
        // while stack top price <= current price, accumulate spans
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span}); // store current price and its span
        return span;            // return only today's span
    }
};
