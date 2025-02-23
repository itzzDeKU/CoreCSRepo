# **Optimizations**  

## **Normalization**  

- The **first step** towards **database optimization**, aimed at reducing **redundancy** and improving **data integrity**.  

### **Functional Dependency (FD)**  

- A **relationship** between attributes in a relation, where the value of one attribute **(determinant)** uniquely determines another **(dependent)**.  
- **Notation:** `X → Y` (X determines Y).  
- **Example:** In a Student table, `Roll_Number → Student_Name`, meaning Roll_Number uniquely determines the Student_Name.  

#### **Types of Functional Dependencies**  

(TBD – Add different types like Partial, Transitive, Trivial, etc.)  

---

## **Indexing**  

- A technique to **speed up data retrieval** by creating **efficient lookup structures** (e.g., B-Trees, Hash Indexes).  
- Reduces the need for **full table scans**, improving query performance.  

---

## **CAP Theorem**  

- States that in a **distributed database**, it's impossible to achieve all three properties **simultaneously**:  
  1. **Consistency (C)** – Every read receives the latest write.  
  2. **Availability (A)** – Every request gets a response, even if failures occur.  
  3. **Partition Tolerance (P)** – The system continues working despite network failures.  
- **Trade-offs:** Choose **CP (Strong Consistency)**, **AP (High Availability)**, or a balance between the two based on system needs.  

---

## **Master-Slave Architecture**  

- A **database replication model** where:  
  - **Master** – Handles **writes** and **updates**.  
  - **Slaves** – Handle **read operations** by replicating the master's data.  
- **Benefits:** Load balancing, backup redundancy, and high availability.  

---

## **Scaling**  

- Expanding database capacity to handle more load.  
- Two types:  
  1. **Vertical Scaling (Scale-Up)** – Adding more resources (CPU, RAM) to a single server.  
  2. **Horizontal Scaling (Scale-Out)** – Adding more servers to distribute the load.  

---

## **Clustering**  

- Clustering involves grouping multiple database servers to work as a single unit for better performance and availability.  
- **Why**: Provides high availability and load balancing.  
- **Example**: MySQL Cluster has multiple nodes where Node A handles writes and Node B replicates data for reads. If Node A fails, Node B can take over.  

---

## **Partitioning**  

- Partitioning splits a database table into smaller parts based on a logical criterion for easier management and better performance.  

### **Types of Partitioning:**  

1. **Range Partitioning** – Data split by ranges.  
   - Example: Orders from **Jan-Mar**, **Apr-Jun**, etc.  

2. **Hash Partitioning** – Data distributed based on a hash function.  
   - Example: Even and odd user IDs.  

3. **List Partitioning** – Based on predefined lists.  
   - Example: Product categories like **Electronics, Furniture, etc.**  

---

## **Sharding**  

- Sharding splits a large dataset into smaller, more manageable pieces (**shards**) stored across multiple servers.  

### **Why Use Sharding?**  

- Improves scalability and performance.  

### **Example:**  

A user database for an app is sharded by regions:  

- **Shard 1**: Users from **North America**.  
- **Shard 2**: Users from **Europe**.  

Each shard works **independently** but together forms the **complete dataset**.  

---

## **Paging**  

Paging is a **memory management technique** where the database breaks data into **fixed-size blocks** called **pages**. It allows efficient data storage and retrieval by mapping these pages between **disk and memory**.  

### **Key Concepts**  

- **Page Size**: Fixed (e.g., **4KB, 8KB**).  
- **Page Table**: Keeps track of where each page resides in **memory or disk**.  
- **Buffer Pool**: Area in memory for frequently accessed pages.  

### **How Paging Works**  

1. Data is stored on disk as pages.  
2. When a query is executed:  
   - Required pages are fetched into memory.  
   - If memory is full, **less-used pages are swapped out** (page replacement).  

### **Advantages**  

- Optimizes database performance by **minimizing disk I/O**.  
- Supports large datasets that exceed memory size.  

### **Challenges**  

- **Page Fault**: When the required page is not in memory, causing a **disk access** (slow).  
- **Thrashing**: Excessive page faults leading to degraded performance.  

---

## **Page Replacement Algorithms**  

When a **page needs to be loaded** into memory and all available slots are full, **Page Replacement Algorithms** decide which page to evict.  

### **Goals of Page Replacement Algorithms**  

1. Minimize page faults.  
2. Retain frequently accessed pages in memory.  
3. Improve system performance.  

### **Types of Page Replacement Algorithms**  

---

### 1. **First-In-First-Out (FIFO)**  

- **Approach**: Evicts the page that has been in memory the longest.  
- **Advantage**: Simple to implement.  
- **Disadvantage**: Doesn’t consider page usage frequency; may evict frequently used pages.  

#### **Example:**  

**Pages in memory**: `[1, 2, 3]`  

**New page**: `4` → Evict `1` (oldest).  

**Result**: `[2, 3, 4]`  

---

### 2. **Least Recently Used (LRU)**  

- **Approach**: Evicts the page that was **least recently accessed**.  
- **Advantage**: Considers usage patterns, reducing unnecessary page faults.  
- **Disadvantage**: Requires additional data structures (e.g., a stack or timestamp) for tracking.  

#### **Example:**  

**Pages in memory**: `[1, 2, 3]`  

**Access sequence**: `1 → 2 → 3 → 4` → Evict `1` (**least recently used**).  

**Result**: `[4, 2, 3]`  

---

### 3. **Optimal Page Replacement (OPT)**  

- **Approach**: Evicts the page that will not be used for the **longest period in the future**.  
- **Advantage**: Produces the **minimum number of page faults**.  
- **Disadvantage**: Not practical, as it requires future knowledge of access patterns.  

#### **Example:**  

**Access sequence**: `1 → 2 → 3 → 4 → 2 → 3`  

**Pages in memory**: `[1, 2, 3]`  

**New page**: `4` → Evict `1` (**used farthest in the future**).  

**Result**: `[4, 2, 3]`  

---

### 4. **Least Frequently Used (LFU)**  

- **Approach**: Evicts the page with the **lowest access frequency**.  
- **Advantage**: Considers usage history.  
- **Disadvantage**: Struggles with recently used but infrequently accessed pages.  

#### **Example:**  

**Pages in memory**: `[1 (3 accesses), 2 (1 access), 3 (1 access)]`  

**New page**: `4` → Evict `2` or `3` (**least frequent**).  

**Result**: `[1, 3, 4]`  

---

### 5. **Clock (Second Chance)**  

- **Approach**: Assigns a **reference bit** to each page. If the bit is `0`, the page is evicted; if `1`, the bit is reset to `0` and the page is given a second chance.  
- **Advantage**: Combines simplicity of FIFO with improved performance.  
- **Disadvantage**: Slightly more complex than FIFO.  

#### **Example:**  

**Pages in memory**: `[1*, 2, 3]` (* indicates reference bit = 1).  

**New page**: `4` → Evict `2` or `3` (**reference bit = 0**).  

**Result**: `[1*, 4, 3]`  

**Commonly Used:** **LRU or Clock Algorithm**.  

---

This version is properly formatted with correct indentation, bullet points, and structure. Let me know if you need further improvements! 🚀
