## Vertical Scaling vs Horizontal Scaling

### Vertical Scaling (Scale Up)

Definition: Adding more resources (CPU, RAM, storage) to a single server.

Example: Upgrading a server from 8 GB RAM to 32 GB RAM.

#### Pros:

- Simpler to implement.
- Easier to manage (single machine).

#### Cons:

- Hardware limits.
- Single point of failure.
- Downtime may be needed for upgrades.

### Horizontal Scaling (Scale Out)

Definition: Adding more machines/instances to handle load.

Example: Adding more servers behind a load balancer.

Pros:

- More fault tolerant.
- Better for large, distributed systems.
- No strict hardware limit.

Cons:

- Increased complexity (distributed systems).
- Requires load balancers, data synchronization, etc.

### Usage

| Criteria        | Vertical Scaling  | Horizontal Scaling |
| --------------- | ----------------- | ------------------ |
| Cost            | Initially cheaper | Costly upfront     |
| Complexity      | Low               | High               |
| Fault Tolerance | Low (SPOF)        | High               |
| Scalability     | Limited Virtually | unlimited          |
