# CS Portfolio – Shadab Chowdhury

This repository is part of my Computer Science portfolio. It contains selected work from CS 255 (System Analysis and Design). These artifacts show how I gathered requirements from a real client scenario and designed a system around those needs.

## DriverPass Project Overview

DriverPass is a client that wants to improve first-time driving test pass rates for students. They asked for a system that would let students:
- Schedule in-person driving lessons with certified instructors
- Access online practice tests and study materials
- Track their progress and readiness for the DMV road test

Instructors also needed to manage their schedules and see student performance. The goal was to replace manual scheduling (phone calls, spreadsheets, etc.) with an integrated platform.

## Artifacts in This Repository

- `BusinessRequirementsDocument.pdf`  
  This document captures the business needs and requirements of the DriverPass system from the client’s perspective. It includes functional requirements (what the system must do) and nonfunctional requirements (security, reliability, performance, etc.).

- `SystemDesignDocument.pdf`  
  This document translates those requirements into a technical design. It includes system architecture details, UML diagrams (use case, activity, sequence, class), and descriptions of how different parts of the system should work together.

Together, these documents show my ability to move from problem definition to a proposed solution.

---

 Reflection

 Briefly summarize the DriverPass project. Who was the client? What type of system did they want you to design?
DriverPass is a driving instruction and test-prep service that wants to help students pass their road test on the first try. They wanted a system that could combine lesson scheduling, learning content (like practice exams and study modules), and student progress tracking. The system also needed to support instructors so they could manage appointments and see how each student is doing.

 What did you do particularly well?
I did a good job translating stakeholder conversations into clear, structured requirements. I separated business goals (“help students pass on the first try”) from specific functional needs (“students can book a driving lesson with an instructor at an available time slot”). I also clearly documented different types of requirements, such as security, reliability, and usability, which shows awareness of real-world constraints. In the system design, I used diagrams to communicate how the system should behave, not just what it should do. That helps both technical and nontechnical audiences understand the plan.

 If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?
I would revise and expand the security and data protection section of the system design. I described roles (student, instructor, admin) and authentication, but I would go deeper on data privacy and recovery. For example, I would add more detail on how personal and scheduling data is protected in storage and in transit, and what the backup and recovery expectations are if the system fails. That level of detail is important for a production system.

 How did you interpret the user’s needs and implement them into your system design? Why is it so important to consider the user’s needs when designing?
I focused on what the users were actually trying to accomplish. Students want convenient lesson booking, realistic practice tests, and a way to see “am I ready yet?” Instructors want an organized schedule and visibility into each student’s progress. I made sure those needs directly turned into features in the design: an online scheduling module, a progress tracking feature, and a training content library.

It’s important to design around user needs because a system can be technically correct and still fail if it doesn’t solve the real pain points. Centering the user early reduces rework later and increases the chance the system will actually get used.

 How do you approach designing software? What techniques or strategies would you use in the future to analyze and design a system?
My approach is:
1. Gather requirements from the client and document them clearly.
2. Separate functional requirements (what the system must do) from nonfunctional requirements (how it must perform).
3. Identify actors and use cases.
4. Create models/diagrams (use case diagrams, sequence diagrams, activity diagrams, class diagrams) to show system behavior and structure.
5. Propose a design that maps directly back to the original requirements.

Going forward, I would keep using that structured flow because it creates traceability. You can point to any part of the design and say, “This exists because the client asked for X.” That traceability is important for communication with both stakeholders and developers.


 Contact
Shadab Chowdhury  
CS 255 – System Analysis and Design
