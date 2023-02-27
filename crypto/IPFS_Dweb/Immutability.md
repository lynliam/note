# Immutablility

IPFS works like git , a version control tool. It only changes the updated parts pointers.

### How to solve the problem that the content is hard to be altered or updated ？

By creating a pointer pointing at the root CIDs，the CID changes but can't impact the unique pointer like the URLs.

```python
   +-----------+ 
   |  Pointer  |
   +-----------+
         ↓
      +-----+
   +--|  C  |-+
   |  +-----+ |
   |          |
+-----+    +-----+
|  A  |    |  B  |
+-----+    +-----+
"hello"    "world"

##just like git

   +-----------+
   |  Pointer  | --------------+
   +-----------+               |
                               ↓
      +-----+               +-----+
   +--|  C  |-+         +-- |  E  | --+
   |  +-----+ |         |   +-----+   |
   |          |         |             |
+-----+    +-----+     +-----+    +-----+
|  A  |    |  B  |     |  A  |    |  D  |
+-----+    +-----+     +-----+    +-----+
"hello"    "world"     "hello"    "IPFS!"

+--------+      +---------+      +----------+
|  User  | ---> | Pointer |      | QmWLd... |
+--------+      +---------+      +----------+
                     |
                     |           +----------+
                     + --------> | Qme1A... |
                                 +----------+
```



### Updating CIDs

* using IPNS to create pointers
* using smart contracts to manages CIDs
  * ***don't really understand***