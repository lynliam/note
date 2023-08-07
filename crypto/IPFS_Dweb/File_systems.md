# File systems and IPFS

the properties of IPFS

- Content addressing means that when files change, the content identifier (CID) of those files changes too.
- Files may be too big to fit in a single block, so IPFS splits the data into  multiple blocks and uses metadata to link it all together.



### Mutable File System(MFS)

Because files in IPFS are content-addressed and immutable, they can  be complicated to edit. Mutable File System (MFS) is a tool built into  IPFS that lets you treat files like you would a regular name-based  filesystem — you can add, remove, move, and edit MFS files and have all  the work of updating links and hashes taken care of for you.

#### Create a directory

The MFS method `ipfs.files.mkdir` creates a new directory at a specified path. For example, to add a directory `example` to our root directory (`/`), run:

```text
await ipfs.files.mkdir('/example')
```

If you want to create a new directory nested under others that don't yet exist, you need to explicitly set the value of `parents` to `true`, like so:

```text
await ipfs.files.mkdir('/my/directory/example', { parents: true })
```

#### [#](https://docs.ipfs.tech/concepts/file-systems/#check-directory-status) Check directory status

The method, `ipfs.files.stat` enables you to check the status of a file or directory on your IPFS node. To check the status of a directory called `example` located within the root directory, you could call the method by running:

```text
await ipfs.files.stat('/example')
```

This method returns an object with a `cid`, `size`, `cumulativeSize`, `type`, `blocks`, `withLocality`, `local`, and `sizeLocal`.

```text
// {
//   hash: CID('QmXmJBmnYqXVuicUfn9uDCC8kxCEEzQpsAbeq1iJvLAmVs'),
//   size: 60,
//   cumulativeSize: 118,
//   blocks: 1,
//   type: 'directory'
// }
```

If you add, move, copy, or remove a file into a directory, the hash of that directory will change with every file modified.

#### [#](https://docs.ipfs.tech/concepts/file-systems/#add-a-file-to-mfs) Add a file to MFS

To add a file to IPFS, use the MFS `ipfs.files.write` method using the command:

```text
await ipfs.files.write(path, content, [options])
```

TIP

This method can create a brand new file that accepts file `content` in multiple formats, in a specified `path` within the IPFS instance by providing the boolean option {`create: true` }.

To add a file object called `examplePic` to the root directory you could run:

```text
await ipfs.files.write('/example.jpg', examplePic, { create: true })
```

This method does not provide a return value.

#### [#](https://docs.ipfs.tech/concepts/file-systems/#view-contents-of-a-directory) View contents of a directory

To check whether the `ipfs.files.write` method has worked as expected, use the `ipfs.files.ls` method to inspect directories on the MFS by running:

```bash
await ipfs.files.ls([path], [options])
```

The method will default to listing the contents of your directory (`/`), or you can choose to specify a specific `path` you'd like to inspect:

```bash
await ipfs.files.ls('/example')
```

This method produces an array of objects for each file or directory with properties such as `name`, `type`, `size`, `cid`, `mode`, and `mtime`. If you wanted to inspect the contents of a `/example` directory, run:

```text
await ipfs.files.ls('/example')
```

#### [#](https://docs.ipfs.tech/concepts/file-systems/#copy-a-file-or-directory) Copy a file or directory

In the Mutable File System, like traditional systems, you can copy a file  or directory to a new location while also leaving it intact at its  source.

You can do this by using the method:

```text
await ipfs.files.cp(...from, to, [options])
```

TIP

This method offers two formatting options for passing the `from` key:

- an existing MFS path to a file or a directory in your node (e.g. `/my-example-dir/my-example-file.txt`)
- an IPFS path to a file or directory hosted either by you or by a peer (e.g. `/ipfs/QmWc7U4qGeRAEgtsyVyeW2CRVbkHW31nb24jFyks7eA2mF`)

The `to` key is the destination path in MFS, and there's an option {`create: true` } that can be used to create parent directories that don't already exist.

You can use this method to perform different operations including:

```text
// copy a single file into a directory
await ipfs.files.cp('/example-file.txt', '/destination-directory')
await ipfs.files.cp('/ipfs/QmWGeRAEgtsHW3ec7U4qW2CyVy7eA2mFRVbk1nb24jFyks', '/destination-directory')

// copy multiple files into a directory
await ipfs.files.cp('/example-file-1.txt', '/example-file-2.txt', '/destination-directory')
await ipfs.files.cp('/ipfs/QmWGeRAEgtsHW3ec7U4qW2CyVy7eA2mFRVbk1nb24jFyks',
 '/ipfs/QmWGeRAEgtsHW3jk7U4qW2CyVy7eA2mFRVbk1nb24jFyre', '/destination-directory')

// copy a directory into another directory
await ipfs.files.cp('/source-directory', '/destination-directory')
await ipfs.files.cp('/ipfs/QmWGeRAEgtsHW3ec7U4qW2CyVy7eA2mFRVbk1nb24jFyks', '/destination-directory')
```

#### [#](https://docs.ipfs.tech/concepts/file-systems/#move-a-file-or-directory) Move a file or directory

MFS allows you to move files between directories using the `ipfs.files.mv`, which looks like this:

```text
await ipfs.files.mv(from, to, [options])
```

`from` is the source path (or paths) of the content you'd like to move, while `to` is the destination path.

You can use this method to perform different operations including:

```text
// move a single file into a directory
await ipfs.files.mv('/example-file.txt', '/destination-directory')

// move a directory into another directory
await ipfs.files.mv('/source-directory', '/destination-directory')

// overwrite the contents of a destination file with the contents of a source file
await ipfs.files.mv('/source-file.txt', '/destination-file.txt')

// move multiple files into a directory
await ipfs.files.mv('/example-file-1.txt', '/example-file-2.txt', '/example-file-3.txt', '/destination-directory')
```

#### [#](https://docs.ipfs.tech/concepts/file-systems/#read-the-contents-of-a-file) Read the contents of a file

The `ipfs.files.read` method allows you to read and, or display the contents of a file in a buffer. The method takes the format:

```text
ipfs.files.read(path, [options])
```

The `path` provided is the path of the file to read, and it must point to a file rather than a directory.

#### [#](https://docs.ipfs.tech/concepts/file-systems/#remove-a-file-or-directory) Remove a file or directory

MFS allows you to remove files or directories using the method:

```text
await ipfs.files.rm(...paths, [options])
```

`paths` are one or more paths to remove.

By default, if you attempt to remove a directory that still has contents,  the request will fail. To remove a directory and everything contained in it, you'll need to use the option `recursive: true`.

```text
// remove a file
await ipfs.files.rm('/my/beautiful/file.txt')

// remove multiple files
await ipfs.files.rm('/my/beautiful/file.txt', '/my/other/file.txt')

// remove a directory and its contents
await ipfs.files.rm('/my/beautiful/directory', { recursive: true })

// remove a directory only if it is empty
await ipfs.files.rm('/my/beautiful/directory')
```



##  Unix File System (UnixFS)

When you add a *file* to IPFS, it might be too big to fit in a single block, so it needs metadata to link all its blocks together. UnixFS is a [protocol-buffers  (opens new window)](https://developers.google.com/protocol-buffers/)-based format for describing files, directories, and symlinks in IPFS. This  data format is used to represent files and all their links and metadata  in IPFS. UnixFS creates a block (or a tree of blocks) of linked objects.

UnixFS currently has [Javascript  (opens new window)](https://github.com/ipfs/js-ipfs-unixfs) and [Go  (opens new window)](https://github.com/ipfs/kubo/tree/b3faaad1310bcc32dc3dd24e1919e9edf51edba8/unixfs) implementations. These implementations have modules written in to run different functions:

- **Data Formats**: manage the serialization/deserialization of UnixFS objects to protocol buffers
- **Importer**: Build DAGs from files and directories
- **Exporter**: Export DAGs

