
-call of shm_open(name) creates shared memory object with the given name, if it
 not already exists.

- shared memory objects are managed in a double linked list

// shared memory struct
// +---------------+
// | 0 | next      |      - points to the next shared memory object
// | 1 | prev      |      - points to the previous shared memory object
// | 2 | id        |      - id of the shared memory object
// | 3 | name      |      - name of the shared memory object
// | 4 | size      |      - size of shared memory, specified by calling shm_size()
// | 5 | frames    |      - list of the frames in physical memory that make the shared memory area
// | 6 | clients   |      - list of client objects. each client represents a process that called
// +---------------+        shm_open() on the shared memory object


// client struct:
// +-----------+
// | 0 | next  |          - pointer to the next client
// | 1 | prev  |          - pointer to the previous client
// | 2 | pid   |          - pid of the process
// | 3 | pages |          - list of pages, which are mapped to the frames of the shared memory area
// +-----------+



Examples

- process 1 and process 2 call shm_open("test") -> a shared memory object with name "test" is created. The client
  list of "test" has the entries [1, 2]. shm_open() returns the id 5 which identifies "test"

- process 1 calls shm_size(5, 5000) -> The size of "test" is 5000 and cannot be changed afterwards.

- a shared memory area is always a multiple of the page/frame size. That is, the size of 5000
  will be rounded up to 8192, which is the size of 2 frames/pages

- these two frames are then allocated in physical memory, e.g. the frames 200 and 201. That is, the frame list
  of "test" is [200, 201]

- process 1 calls shm_map(null, 5) -> two pages in the virtual address space of process 1, e.g. 3092 and 3093,
  are mapped to the frames 200 and 201. That is, the client of "test" representing process 1 stores
  the pages [3092, 3093]

- process 2 calls shm_map(null, 5) -> two pages in the virtual address space of process 1, e.g. 9346 and 9347,
    are mapped to the frames 200 and 201. That is, the client of "test" representing process 2 stores
    the pages [9346, 9347]


storing the mapped pages in the client structs will be necessary when shm_close() is called by both processes.
Then, these pages have to be re-mapped to other frames in order to make the former shared memory "private" for
each process  (TODO)



Assign3:
******* -u param **************************
Switch nur erlaubt vom Hypster:
Wie ist der generelle Ablauf?
1. userprocess wirft exception
2. mipster/hardware fängt es auf mit #runUntilException() und setzt trap
3. daraufhin kommt man wieder in die runOrHostUntilExitWithPageFaultHandling() vom mipster
3.1.   "if (getParent(fromContext) != selfie_ID())" wird kontrolliert
3.1.1. da mipster läuft, merkt dieser, dass er nicht das OS ist, sondern nur handware-> geh zum OS. Dieser wird alles regeln
3.2.   er scheduled zu dem OS aka den parent. Hier muss kontrolliert werden, ob parent == OS == hypster_ID();
3.2.1. hier wird also gschaut werden ob der User-Process vom OS gestartet wurde (-u param). Ansonsten fail

******* -k param **************************




