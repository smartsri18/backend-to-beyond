## Consistent Hashing

Consistent hashing is a hashing technique used to distribute data across multiple nodes (servers) in a way that minimizes the amount of data that needs to be moved when nodes are added or removed.

> Traditional hashing (like hash(key) % n) changes drastically when n (number of servers) changes — all keys might get reassigned. Consistent hashing solves this.

### Key Idea

Instead of mapping keys directly to servers, both keys and servers are placed on a ring (or a circle) using a hash function (like SHA-1 or MD5).

- Each server is assigned a position on the ring based on its hash.
- Each key is hashed to a point on the ring, and it's stored in the first server clockwise from that point.

### How It Works (Simple Steps)

- Hash all servers to a number between 0 and 2³² (forming a circle).
- Hash all keys similarly to a point on the circle.
- Each key is assigned to the nearest server in clockwise direction.

If a server is added or removed:

- Only a small portion of keys get remapped.
- Contrast this with modulo hashing where almost all keys may get remapped.

### Enhancements

- Virtual Nodes
  Each physical server is represented by multiple points (virtual nodes) on the ring to ensure even distribution and avoid hotspots.

Example:
Server A → hash(A1), hash(A2), hash(A3)…
This ensures a more balanced distribution of keys.

### Comparison to Naive Hashing

| Aspect                | Modulo Hashing                         | Consistent Hashing  |
| --------------------- | -------------------------------------- | ------------------- |
| Key distribution      | Uniform but reshuffles on node changes | Mostly stable       |
| Scalability           | Poor                                   | Excellent           |
| Node addition/removal | Disruptive                             | Minimal impact      |
| Use cases             | Small scale                            | Distributed systems |

### Use Cases of Consistent Hashing

1. Distributed Caching (e.g., Memcached, Redis Cluster)

   - Consistent hashing helps avoid cache misses when servers are added or removed.
   - Clients can directly map keys to servers without needing central coordination.

2. Sharding in Distributed Databases

   - Systems like Cassandra and DynamoDB use consistent hashing to partition data efficiently.

3. Content Delivery Networks (CDNs)

   - Helps in locating the optimal cache node that should serve a user request.

4. Load Balancing
   - Used when there's a need for sticky routing (client → same server), especially in systems where state is important.
