# Contributing to CIS2520 Notes Repository

Thank you for contributing to the CIS2520 Notes Repository! This repository is designed to help students review for exams by providing organized notes and code samples. Follow these steps to contribute:

---

## How to Contribute

### 1. Fork the Repository
- Click the **Fork** button at the top of the repository page.
- This will create a copy of the repository in your GitHub account.

### 2. Clone the Forked Repository
- Clone your forked repository to your local machine:
  ```bash
  git clone https://github.com/your-username/CIS2520-notes.git
  ```
- Replace `your-username` with your GitHub username.
- Navigate to the repository folder:
  ```bash
  cd CIS2520-notes
  ```

### 3. Create a New Branch
- Create a new branch for your changes:
  ```bash
  git checkout -b your-branch-name
  ```
- Use a meaningful name, such as `week7-trees` or `add-binary-search-notes`.

---

### 4. Add Your Notes
- Navigate to the relevant folder (e.g., `week6-hashingandtrees`) or create a new folder if necessary.
- Inside each folder, ensure the following structure:
  ```
  weekX-topic/
  ├── images/           # Folder for images
  │   └── example.png   # Any relevant images
  ├── notes.md          # Markdown file for notes
  ```

#### **Markdown Notes Format**
Use the following format for the `notes.md` file:
```markdown
# Topic Title
## Overview
Brief summary of the topic.

## Key Concepts
- Concept 1
- Concept 2

## Code Examples
```c
// Example code snippet
int main() {
    return 0;
}
```

## Images
Use the `images/` folder to store any visuals related to the topic. Refer to the images in the notes using relative paths:
```markdown
![Example Image](images/example.png)
```
```

---

### 5. Commit Your Changes
- Stage your changes:
  ```bash
  git add .
  ```
- Write a clear and descriptive commit message:
  ```bash
  git commit -m "Added notes for week6 - Hashing and Trees"
  ```
---

### 6. Push Your Branch to GitHub
- Push your branch to your forked repository:
  ```bash
  git push origin your-branch-name
  ```

---

### 7. Submit a Pull Request
1. Go to the **Pull Requests** tab in the original repository.
2. Click **New Pull Request**.
3. Compare changes:
   - **Base repository**: `original-repo/main`
   - **Head repository**: `your-username/your-branch-name`
4. Click **Create Pull Request**.
5. Fill out the pull request form:
   - Add a descriptive title (e.g., `Added Binary Search Tree Notes for Week6`).
   - Provide a brief explanation of your changes.
6. Submit your pull request.

---

## Contribution Guidelines
1. **Organized Structure**: Maintain the folder structure (`images/` and `notes.md`) for each topic.
2. **Clarity**: Keep notes simple and beginner-friendly.
3. **Plagiarism**: Avoid copying material without proper citations.
4. **Code Samples**: Ensure all code examples are properly tested.
5. **File Naming**: Use descriptive file names (e.g., `week5-queues.md`).

---

## Need Help?
If you encounter issues or have questions:
- Open an issue in the repository.
- Start a discussion in the **Discussions** tab.

Thank you for contributing! 😊
