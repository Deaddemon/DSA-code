resources: <br>
https://www.geeksforgeeks.org/deque-cpp-stl/  <br>
 


double-ended queue<br>
--------------------------------
TC:<br>
Accessing Elements- O(1)<br>
Insertion or removal of elements- O(N)<br>
Insertion or removal of elements at start or end- O(1)<br>
<br>

```c++
deque<int> dq;
dq.push_back(10);
dq.push_back(10);
dq.pop_front();
dq.pop_back();
dq.at(1);
dq.front();
dq.back();
````
 
