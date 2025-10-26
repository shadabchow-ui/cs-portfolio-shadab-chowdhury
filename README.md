# CS Portfolio – Shadab Chowdhury

This repository is my Computer Science portfolio. It collects selected work from multiple courses in the program and shows how I’ve grown across analysis, design, implementation, testing, and data structures. Each section below explains what the artifact is, why it matters, and how I approached the work.

---

## CS 255 – System Analysis and Design

### Project Overview
DriverPass is a client focused on helping students pass their driving test on the first try. They wanted a system that would let students:
- Schedule in-person driving lessons with certified instructors
- Access online practice tests and study materials
- Track their progress and readiness for the DMV road test

Instructors also needed tools to manage their schedules and view student performance. The goal was to replace manual scheduling (phone calls, spreadsheets, back-and-forth messages) with one unified platform.

### Artifacts Included
- `BusinessRequirementsDocument.pdf`
- `SystemDesignDocument.pdf`

**BusinessRequirementsDocument.pdf**  
This document captures the client’s business needs, goals, and constraints. It includes functional requirements (what the system must do, like scheduling and progress tracking) and nonfunctional requirements (security, reliability, availability, etc.). It also explains why these requirements matter to DriverPass’s mission.

**SystemDesignDocument.pdf**  
This document translates the requirements into a system design. It includes UML diagrams (use case, activity, sequence, class), describes system components, and explains how the different parts of the platform should interact. This is how the abstract “what we need” becomes something developers can actually build.

Together, these two documents show my ability to gather client requirements, organize them clearly, and design a system that meets those needs.

### Reflection
**What did I do particularly well?**  
I did well turning vague client goals into specific, testable requirements. I separated business goals (“students should pass on the first try”) from concrete features (“students can book a driving lesson with an instructor who has available time”). I also documented both functional and nonfunctional requirements, which is important in real projects because performance, security, and reliability matter just as much as features.

I also used diagrams to communicate system behavior in a way that both technical and nontechnical people can follow. That’s a big part of systems work: it’s not just building it, it’s making sure everyone understands what’s being built.

**If I could revise one part, what would I improve?**  
I’d go even deeper on security and data protection. I covered roles (student, instructor, admin) and authentication, but I would expand on privacy, backups, and recovery. For example: how fast does the system need to recover if it goes down? How do we protect personal info and scheduling data? Adding that kind of detail would make the design feel closer to production-level.

**How did I interpret the user’s needs and incorporate them? Why does that matter?**  
I looked at what each user type is actually trying to do:
- Students want: “Can I book a lesson that fits my schedule? Am I ready for my test yet?”
- Instructors want: “Is my schedule organized? What does this student still need?”

Those needs drove the features I designed: scheduling, progress tracking, and online study materials. It’s critical to design around real user needs because a system can be technically correct and still fail if users don’t want to use it. Good design means adoption is built in.

**How do I approach designing software?**  
My approach is:
1. Gather requirements from the client.
2. Separate functional requirements (what it should do) and nonfunctional requirements (how it should behave).
3. Identify actors and use cases.
4. Model the system (UML diagrams, components, data flow).
5. Map every part of the design back to a requirement so nothing is random.

This approach creates traceability. You can always point to something in the design and say “this exists to solve that user problem.”

---

## CS 320 – Software Testing, Automation, and Quality

### Artifacts Included
- `cs320-project-one/Contact.java`
- `cs320-project-one/ContactService.java`
- `cs320-project-one/ContactTest.java`
- `cs320-project-one/ContactServiceTest.java`
- `cs320-project-two/cs320-project-two-summary-and-reflection.pdf`

These artifacts demonstrate writing code that manages data safely, plus building automated tests to enforce correct behavior and prevent regressions.

**Project One (Contact Service + Tests)**  
- `Contact.java` and `ContactService.java` handle creating, storing, and updating contact information.
- `ContactTest.java` and `ContactServiceTest.java` are JUnit tests that verify valid behavior and reject invalid behavior.

The important part here is that the code enforces rules (like max lengths and required formats) and the tests prove the rules are actually enforced. This is the core of reliable software: not just writing logic, but locking it down with automated tests.

**Project Two (Summary and Reflection Report)**  
- The PDF in `cs320-project-two/` explains testing strategy, quality concerns, and how different testing approaches map to requirements.

### Reflection
**How can I ensure that my code, program, or software is functional and secure?**  
I use two layers: validation and verification.

Validation means the code itself refuses bad input. For example, in the contact service, each field (like phone number, name, ID) has strict length and format rules. The service won’t create or update a contact if the data is invalid. That protects data integrity and reduces risk.

Verification means I prove the code works using automated unit tests. The JUnit tests check normal behavior and edge cases (bad IDs, invalid phone numbers, etc.). If something changes later and breaks a rule, a test fails immediately. That’s how you keep code both functional and safer over time.

**How do I interpret user needs and incorporate them into a program?**  
I try to translate “what the user is trying to do” into “what the code must guarantee.”  
For example, the user need here was: “Store contact info and update it safely without corrupting it.”  
That became requirements like:
- Each contact must have a unique, stable ID.
- Phone numbers must match a fixed length.
- Names and addresses can’t overflow allowed size.
- Updates should work but not break the rest of the data.

Those needs directly shaped `ContactService`, and then the tests enforce those behaviors. So requirements don’t just live in documentation — they live in code and tests.

**How do I approach designing software?**  
My pattern now is:
1. Define focused classes with clear responsibility.  
   - `Contact` = data + validation  
   - `ContactService` = storage + allowed operations
2. Write tests that describe expected behavior from the outside.
3. Hit edge cases, not just the happy path.

This matters because most real-world failures come from bad input, not perfect input. Designing with tests up front forces you to think like, “What could break this?” That mindset is a core part of quality.

---

## CS 300 – Data Structures and Algorithms

### Artifacts Included
- `cs300/cs300-runtime-and-memory-analysis.pdf`
- `cs300/cs300-project-two-course-sorter.cpp` (final Project Two source code that loads, sorts, and prints the Computer Science course list in alphanumeric order)

These artifacts show how I analyzed performance tradeoffs between data structures, and then used those decisions to build a real working program.

### What was the problem I was solving in this course?
I needed to read in a list of Computer Science courses and then output them in clean alphanumeric order (like CS 100, CS 200, CS 300…). Underneath that, the program needed to store course data, access it efficiently, and then sort it for final output. In a real advising or planning tool, that’s how you’d present the catalog to a student.

### How did I approach the problem? Why are data structures important here?
I compared different data structures — vectors/arrays, hash tables, and binary search trees — in terms of:
- time complexity (insert, lookup, traversal)
- memory usage
- how easy it is to produce sorted output

For example:
- A hash table is great for fast lookups of “give me course CS 200,” but it doesn’t keep things in sorted order.
- A tree or even a vector + sort is better for final alphabetical/ID-ordered printing.
- Memory overhead matters if you’re storing a lot of courses or prerequisites.

Instead of just writing “some code that works,” I picked structures based on access pattern and output requirements. That’s a shift toward thinking like an engineer, not just a coder.

### How did I overcome roadblocks?
Most issues were:
1. Parsing and loading the data into the structure cleanly
2. Making sure the final output really was in the correct alphanumeric order

I solved that by breaking the program into phases: load → store → sort → print. I debugged by printing intermediate results for each phase, instead of trying to debug the entire pipeline at once. That kept it under control.

### How has this changed how I design software?
Before this course, “design” mostly meant “plan functions and classes.” After this course, design also means “choose the right data structure so the operations you need are cheap, predictable, and scalable.”

Now when I start something, I ask:
- What are we doing the most: inserting? searching? ordering? updating?
- Which structure makes those operations efficient?

That mindset is critical for performance, and it also affects how your program will scale when the data grows.

### How has this changed how I write maintainable, readable, adaptable code?
I focused more on separating logic into steps and naming things clearly so someone else can reuse it. For example:
- I keep course-loading separate from sorting and printing.
- I write code so that if the requirement changes later (like “print by prerequisite order instead of alphanumeric”), I can swap out the traversal or sort logic without rewriting the entire program.

That’s maintainability: being able to adapt the behavior without tearing everything apart.

---

## Contact

Shadab Chowdhury  
Computer Science Program
Southern New Hampshire University
