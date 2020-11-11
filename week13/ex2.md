## Recovery ##

We should use deadlock recovery if we care about the performance. It is better to recover the deadlock rather than break any deadlock condition.

## Prevention ##

We should use deadlock prevention if the safety and stability is preferred over the performance. We have no intention to handle deadlock and recover them, but it is possible to neglect one of the deadlock conditions instead.

## Avoidance ##

We should choose this technique if we deadlocks are not preferred, but we still care about the performance, and have no intention to breal some deadlock condtions.