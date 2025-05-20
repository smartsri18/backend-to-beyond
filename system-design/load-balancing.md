## Load Balancer

Load balancing is the process of distributing incoming network traffic or workloads across multiple servers (or computing resources) to ensure no single server becomes overwhelmed. It’s crucial for:

- Scalability: Easily adding more servers to handle more traffic.
- Availability: Ensuring service continues even if some servers fail.
- Performance: Reducing latency and speeding up response time.

### How Load Balancing Works (Basic Flow)

- Client sends a request.
- Load balancer receives the request.
- It selects an available backend server based on a balancing algorithm.
- Forwards the request to that server.
- Server responds back to client via the load balancer (or sometimes directly if using direct server return).

### Common Load Balancing Algorithms

| Algorithm               | Description                                                                            |
| ----------------------- | -------------------------------------------------------------------------------------- |
| Round Robin             | Assigns each request to the next server in a cycle. Simple, but doesn't consider load. |
| Least Connections       | Sends request to the server with the fewest active connections.                        |
| IP Hashing              | Uses client IP hash to choose a server. Ensures session stickiness.                    |
| Weighted Round Robin    | Servers get requests based on assigned weights (better servers handle more).           |
| Random with Two Choices | Pick two servers at random and choose the less busy one. Efficient and scalable.       |

### Load Balancer Responsibilities

- Health Checks: Monitors servers and routes traffic only to healthy ones.
- SSL Termination: Can handle HTTPS encryption/decryption.
- Sticky Sessions: Ensures user session goes to the same server.
- Rate Limiting / Throttling: Protects backend from abuse.

### Where Is Load Balancing Used?

- Web Servers: To distribute HTTP requests across multiple backend servers.
- Microservices: Balancing requests across multiple service instances.
- Databases: For read replicas or sharding.
- CDNs (Content Delivery Networks): Serving static files from geographically closer servers.
