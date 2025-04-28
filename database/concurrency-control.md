## Shared Locks (S-locks)

- A shared lock is used when a transaction only wants to read a data item.
- Multiple transactions can hold shared locks on the same item at the same time — because just reading doesn't cause conflicts.

> Transaction T1 and T2 can both read customer account A at the same time.

## Exclusive Locks (X-locks)

- An exclusive lock is used when a transaction wants to write (update/insert/delete) a data item.
- Only one transaction can hold an exclusive lock at a time, and no other transaction (even a reader) can access it.

> If T1 is updating account A, T2 must wait — it can neither read nor write A until T1 finishes.

## Deadlocks

- A deadlock happens when two (or more) transactions are waiting for each other’s locks, and none can proceed.

> T1 locks A and wants B. T2 locks B and wants A. Now, T1 is waiting for T2, and T2 is waiting for T1 → Deadlock.

### Handling deadlocks:

- Detection and Recovery: Find cycles and roll back one transaction.
- Prevention: Impose an order for acquiring locks (e.g., always lock A before B).

## Two-Phase Locking (2PL)

- Two-phase locking is a protocol that ensures serializability (correctness) of transactions.

### Growing Phase:

- Transaction can acquire locks.
- It cannot release any lock yet.

### Shrinking Phase:

- Transaction can release locks.
- It cannot acquire any new locks.

> Important point:
> Once a transaction releases any lock, it cannot ask for any new locks.

Example:
T1 locks A (shared lock to read).
T1 locks B (exclusive lock to update).
(No more locks can be acquired after any lock is released.)
T1 releases locks after work is done.

```
> Advantage: Guarantees serializability.
> Disadvantage: Can cause deadlocks.
```

> Double-booking problem is a real-world analogy of a concurrency issue that two-phase locking (2PL) can solve.
