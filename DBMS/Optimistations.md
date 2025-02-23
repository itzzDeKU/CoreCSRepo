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

- A **group of servers** working together as a **single database system**.  
- **Types:**  
  - **Shared Nothing (Each node has its own data)**.  
  - **Shared Disk (All nodes access the same storage)**.  

---  

## **Partitioning**  

- Splitting large datasets into **smaller, manageable parts** across multiple storage units.  
- **Types:**  
  1. **Horizontal Partitioning** – Rows are divided across multiple tables.  
  2. **Vertical Partitioning** – Columns are divided for efficient query optimization.  

---  

## **Sharding**  

- A type of **horizontal partitioning** where data is distributed across multiple **database instances** to **improve performance** and **scalability**.  
- Each shard operates **independently**, reducing load on a single database.  
