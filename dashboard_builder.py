import os
import json

def build_index():
    base_dir = r"E:\LeetCode-Solutions"
    output_file = os.path.join(base_dir, "index.js")
    
    problems = []
    
    # Iterate through topic folders
    for topic in os.listdir(base_dir):
        topic_path = os.path.join(base_dir, topic)
        if not os.path.isdir(topic_path) or topic.startswith("."):
            continue
            
        for filename in os.listdir(topic_path):
            file_path = os.path.join(topic_path, filename)
            if not os.path.isfile(file_path):
                continue
                
            name, ext = os.path.splitext(filename)
            ext = ext.lstrip('.')
            
            # Map extension to language name
            lang_map = {
                'cpp': 'C++',
                'java': 'Java',
                'py': 'Python',
                'c': 'C',
                'cs': 'C#',
                'js': 'JavaScript',
                'ts': 'TypeScript',
                'php': 'PHP',
                'swift': 'Swift',
                'kt': 'Kotlin',
                'dart': 'Dart',
                'go': 'Go',
                'rb': 'Ruby',
                'scala': 'Scala',
                'rs': 'Rust',
                'sql': 'SQL',
                'bash': 'Bash',
                'sh': 'Bash'
            }
            lang = lang_map.get(ext, ext)
            
            # Use relative path for the link
            rel_path = f"{topic}/{filename}"
            
            problems.append({
                "title": name,
                "topic": topic,
                "language": lang,
                "path": rel_path
            })
            
    with open(output_file, "w", encoding="utf-8") as f:
        f.write("const problemsData = ")
        json.dump(problems, f)
        f.write(";\n")
        
    print(f"Successfully generated index.js with {len(problems)} entries.")

if __name__ == "__main__":
    build_index()
