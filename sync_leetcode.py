import os
import sys
import json
import logging
import argparse
import datetime
import warnings

# Suppress harmless RuntimeWarning from dataclasses_json about 'NoneType'
warnings.filterwarnings("ignore", category=RuntimeWarning)

# We import leetcode_export directly since it will be installed via pip (or locally)
try:
    from leetcode_export.leetcode import LeetCode
except ImportError:
    # Fallback for local execution if the package isn't pip installed but resides nearby
    sys.path.append(os.path.join(os.path.dirname(__file__), "..", "leetcode-export-tool"))
    from leetcode_export.leetcode import LeetCode

def main():
    logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")
    
    # 1. Determine Cookie Source (GitHub Secret vs Local File)
    cookies = os.environ.get("LEETCODE_COOKIE")
    if not cookies:
        local_cookie_path = os.path.join(os.path.dirname(__file__), "..", "leetcode_cookies.txt")
        if os.path.exists(local_cookie_path):
            with open(local_cookie_path, "r") as f:
                cookies = f.read().strip()
        else:
            logging.error("No LEETCODE_COOKIE environment variable and no local cookies file found.")
            sys.exit(1)
            
    leetcode = LeetCode()
    if not leetcode.set_cookies(cookies):
        logging.error("Failed to authenticate with LeetCode cookies.")
        sys.exit(1)
        
    # 2. Setup Directories
    out_dir = os.path.dirname(__file__) # The repository root
    
    logging.info("Exporting LeetCode submissions...")
    
    processed_slug_lang = set()
    
    cache_file = os.path.join(out_dir, "problem_cache.json")
    synced_file = os.path.join(out_dir, "synced_submissions.json")
    
    if os.path.exists(cache_file):
        with open(cache_file, "r", encoding="utf-8") as f:
            problem_cache = json.load(f)
    else:
        problem_cache = {}
        
    if os.path.exists(synced_file):
        with open(synced_file, "r", encoding="utf-8") as f:
            synced_submissions = set(json.load(f))
    else:
        synced_submissions = set()

    newly_synced = []
    
    try:
        for submission in leetcode.get_submissions():
            if str(submission.id) in synced_submissions:
                logging.info("Reached already synced submissions. Stopping export.")
                break
                
            newly_synced.append(str(submission.id))
            
            if submission.status_display != "Accepted":
                continue
                
            slug_lang = (submission.title_slug, submission.lang)
            if slug_lang in processed_slug_lang:
                continue
            processed_slug_lang.add(slug_lang)
            
            if submission.title_slug in problem_cache:
                problem_title, topics = problem_cache[submission.title_slug]
            else:
                problem = leetcode.get_problem_statement(submission.title_slug)
                if not problem:
                    continue
                topics = [tag['name'] for tag in problem.topic_tags] if hasattr(problem, 'topic_tags') and problem.topic_tags else ['Uncategorized']
                problem_title = problem.title
                problem_cache[submission.title_slug] = (problem_title, topics)
                # Save cache periodically
                with open(cache_file, "w", encoding="utf-8") as f:
                    json.dump(problem_cache, f)
            
            # Clean topic names for Windows/Linux filesystem
            topics = [t.replace('<', '').replace('>', '').replace(':', '').replace('"', '').replace('/', '').replace('\\', '').replace('|', '').replace('?', '').replace('*', '') for t in topics]
            
            for topic in topics:
                topic_dir = os.path.join(out_dir, topic)
                if not os.path.exists(topic_dir):
                    os.makedirs(topic_dir)
                    
                filename = f"{problem_title}.{submission.extension}"
                filename = filename.replace('<', '').replace('>', '').replace(':', '').replace('"', '').replace('/', '').replace('\\', '').replace('|', '').replace('?', '').replace('*', '')
                
                filepath = os.path.join(topic_dir, filename)
                
                if not os.path.exists(filepath):
                    logging.info(f"Writing {filepath}")
                    with open(filepath, "w", encoding="utf-8") as f:
                        f.write(submission.code)
    finally:
        with open(cache_file, "w", encoding="utf-8") as f:
            json.dump(problem_cache, f)
            
        synced_submissions.update(newly_synced)
        with open(synced_file, "w", encoding="utf-8") as f:
            json.dump(list(synced_submissions), f)
                    
if __name__ == "__main__":
    main()
