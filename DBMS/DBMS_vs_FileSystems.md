# DBSMS vs FileSystems

## Why DBMS Over File SYSTEMS

Traditional file-based data management has several challenges, which DBMS helps to overcome:  

1. **Redundancy & Inconsistency** – Duplicate data across multiple files leads to storage waste and inconsistencies when updates aren't synchronized.  
2. **Difficult Data Access** – Retrieving specific data requires complex code in file systems, whereas DBMS provides efficient query mechanisms.  
3. **Data Isolation** – Data spread across multiple files makes integration and retrieval difficult. DBMS centralizes data for better accessibility.  
4. **Integrity Issues** – Enforcing data accuracy and consistency (e.g., constraints like unique IDs) is complex in file-based systems. DBMS maintains integrity through constraints.  
5. **Atomicity Issues** – Transactions (e.g., transferring money between accounts) must be fully completed or fully rolled back. DBMS ensures atomic operations.  
6. **Concurrency Problems** – Multiple users accessing/modifying data simultaneously can cause conflicts. DBMS manages concurrent access with locking and transaction controls.  
7. **Security Risks** – File-based storage lacks proper authentication and access controls. DBMS enforces role-based security and permissions.

## File Based vs DBMS Approaches

## Performance & Scalibility Comparison
