# C Blunt

## C#, but it's not *cutting* edge.

C Blunt is a project that branched off of [csnative](https://github.com/User0332/csnative) in response to the many problems faced in translating C# to C++ code. C Blunt aims to be a stripped-down (or entirely different, depending on how you see it) but feature-rich version of C#, losing capabilities like reflection and the standard library for native code translation. C Blunt tries to keep most of the standard library, but certain barriers (such as name clashing between `IEnumerable` and `IEnumerable<T>`) force it to change some semantics; for example, as a result of the non-generic `IEnumerable` interface not being available, `System.Array` is a generic type.