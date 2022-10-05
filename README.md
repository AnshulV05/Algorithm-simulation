# Algorithm-Simulation
This repository contains basic implementations of some popular Algorithms.

### Rivest-Shamir-Adleman (RSA) key encryption
The RSA is a public-key cryptosystem that is widely used for secure data transmission.

Consider an example where person **A** has to send a number **x** to person person **B**. <br>
The algorithm involves four steps: <br>
key generation, key distribution, encryption, and decryption.

1. B chooses two large primes **p** and **q**, let their product be **n = p.q** and since p and q are prime we know that **$\Phi(n) = (p-1)\times (q-1)$**
2. Now B chooses a number **a** coprime to $\Phi(n)$ and sends a and n publicly to A.
3. A recieves the keys a and n and sends back **c = x^a (mod n)** publicly to B.
4. Decryption is done by B by taking **c^(a_inverse) mod n** where **a_inverse** is the **inverse modulo** of a with respect to $\Phi(n)$.

The security of RSA relies on the practical difficulty of factoring the product of two large prime numbers, the "factoring problem". And hence difficulty in computation of phi 
and hence a_inverse. <br>

Detailed information about the algorithm can be found in this link.
[RSA](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) 

### Miller-Rabin
The Miller–Rabin primality test or Rabin–Miller primality test is a **probabilistic primality test**, an algorithm which determines whether a given number is likely to be prime.
The algorithm involves the use of property that for a given odd integer n > 2, if n is 2s⋅d + 1 where s and d are positive integers and d is odd and there is an integer a, called a base, such that 0 < a < n. Then, n is said to be a strong probable prime to base a if one of these congruence relations holds: <br>
**a^(d) is 1 modulo n** <br>
**a^((2^r).d) is -1 modulo n** <br>

Detailed information about the algorithm can be found in this link.
[Miller-Rabin](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test) 

### Diffie-Helmann
**Diffie-Helmann** is one of the earliest practical examples of public key exchange implemented within the field of cryptography. Published in 1976 by Diffie and Hellman, this is the earliest publicly known work that proposed the idea of a private key and a corresponding public key.

Consider an example where **A** and **B** have to agree on some key which is to kept private from the public. 
The algorithm is implemented through the following steps: <br>
1. Initially they agree on some large prime **p** and its generator **g**. The values of *p* and *g* are known publicly. <br>
2. Next they choose two numbers individually, Suppose A chooses **a** and B chooses **b**.
3. They send **a' = g^(a) mod p** and **b' = g^(b) mod p** respectively through the public channel.
4. A calculates **b'^(a) mod p** which is **g^(ab) mod n** and B calculates **a'^(b) mod p** which is the same **g^(ab) mod n** hence they reach a common key.

Detailed information about the algorithm can be found in this link. [Diffie-Helmann](https://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange)

### Dijkstra's_algorithm
**Dijkstra's algorithm** is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.
For a given source node in the graph, the algorithm finds the shortest path between that node and every other. It can also be used for finding the shortest paths from a single node to a single destination node by stopping the algorithm once the shortest path to the destination node has been determined. For example, if the nodes of the graph represent cities and edge path costs represent driving distances between pairs of cities connected by a direct road (for simplicity, ignore red lights, stop signs, toll roads and other obstructions), Dijkstra's algorithm can be used to find the shortest route between one city and all other cities.

I have Implemented the algorithm making the use of **Priority Queues** but the same can be done using **Unordered Sets**.
The Graph class consists of the collection of vertices **V** and edges between the vertices **E** , 
The algorithm is implemented in the following way: <br>
1. Create a hasMap **d** for vertex to Distance of vertex. Initialize distances of all vertices as infinite.
2. Create an empty Priority Queue pq. Every item of pq is a Vertex. <br>
   Distance of a vertex is mapped to its Node using a HashMap. The distance of a node is used to compare elements in the priority queue.
3. Insert source vertex into pq and make its distance as 0.
4. While either pq doesn't become empty: <br>
  a) Extract minimum distance vertex from pq. Let the extracted vertex be u. <br>
  b) Loop through all adjacent of u and do following for every vertex v.
        If dist[v] > dist[u] + |E(u,v)| <br>
          &nbsp; 1) Remove v from pq. <br>
          &nbsp; 2) Update distance of v, i.e., do dist[v] = dist[u] + weight(u, v). <br>
          &nbsp; 3) Insert v into the pq. <br>
Finally the map contains required distances.

Detailed information about the algorithm can be found in this link. [Dijkstra's_algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

