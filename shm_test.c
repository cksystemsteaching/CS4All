int main() {
  // little program to demonstrate usage of shared memory objects
  int  id;
  int  shm1;
  int  shm2;
  int  shSize1;
  int* addr;
  id      = 1;
  shSize1 = 4;

  id = shm_open(id);
  // Creates or opens a new shared memory object and returns a descriptor (OS identifier) for it.
  // In case of error, it returns -1.
  id = 1;
  shm_size(id, shSize1);
  // Sets or returns the size (in bytes) of the shm object with identifier id.
  // If the object had size zero, it sets the size to shSize and returns shSize.
  // If the object had some previously set size actSize, then it ignores shSize and simply returns actSize.

  //shm_map(addr, id1);
  // Maps the virtual address addr to the start of the shared memory identified by id.
  // If addr is zero, then memory is allocated first, of the size equal to the shared memory size.
  // Returns virtual address actually used for mapping, 0 for error.

  shm_close(id);
  // Decouples the calling process from the shared memory object with descriptor id.
  // Previously mapped memory is now private to the process.
  // After all processes have closed their access to a shared memory object, the OS should
  // free the resources associated with the object.
}
