
### Naive method for String Matching 
```cpp
for (int i = 0; i <= N - M; i++) {

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) // M is size of pattern
            cout << "Pattern found at index " << i << endl;
    }
```


### Rabin Karp String Matching 
Main idea is to use hash function. Storing string in form of number and that too using hash functions.
<br>
pattern size = 4 <br>
A B C A D E <br>
Hash(A B C A) = Ax^3 + Bx^2 + Cx + A   <br>
Hash(B C A D) = (H - Ax^3)x + D <br>

The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).<br>

```cpp
// d is the number of characters in the input alphabet
#define d 256
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
 
            if (j == M)
                cout << "Pattern found at index " << i
                     << endl;
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}
```
