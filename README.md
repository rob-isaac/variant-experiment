# variant-experiment

This repository sets-up a small benchmark to compare the overhead
of low-cost function calls for different polymorphism implementations.
The three implementations considered are:
 1. Virtual Base Class
 2. Variant Base Class with Inlined Implementation
 3. Variant Base Class with Call-Stack Implementation

Running on my local machine showed a call-time ordering of:

T(2) < T(1) < T(3)

Meaning that the inlined variant implementation has the least
overhead and the Call-Stack variant implementation had the
most overhead.
