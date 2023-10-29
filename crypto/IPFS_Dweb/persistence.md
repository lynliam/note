# Persistence permanence, and pinning

One goal of IPFS is to preserve humanity's history by letting users store data while minimizing the risk of that data being lost or accidentally deleted. This is often referred to as permanence. Because the disk storage is limited, which reverse with the goal of IPFS. So we need **tradeoff**.  

* **garbage collection** 

IPFS uses garbage collection to free disk space on your IPFS node by deleting data that it thinks is no longer needed.

* **Pinning in context**
  - The universal way is by adding a low-level [local pin](https://docs.ipfs.tech/how-to/pin-files/). This works for all data types and can be done manually, but if you add a file using the CLI command [`ipfs add`](https://docs.ipfs.tech/reference/kubo/cli/#ipfs-add), your IPFS node will automatically pin that file for you.
  - When working with files and directories, a better way may be to add them to the local [Mutable File System (MFS)](https://docs.ipfs.tech/concepts/glossary/#mfs). This protects the data from garbage collection in the same way as local pinning but is somewhat easier to manage.
* **Pinning services**

Using pinning service offered by third-parts ensure the data is always ready to be searched.

* **Long-term storage**

Filecoin

* ### IPFS + Filecoin solutions

Combining the two means that when you upload a file, that file is immediately available for download. Additionally, combined IPFS + Filecoin solutions will periodically bundle data and create a deal with a reputable Filecoin storage provider, ensuring that the data is available in long-term storage.