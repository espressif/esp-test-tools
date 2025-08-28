#!/usr/bin/env bash
set -euo pipefail

# Purpose of this script:
# Ensure that the author of the latest commit is in a predefined whitelist.
# - If not, the pipeline fails, prompting the user to amend the commit author locally to somebody in the whitelist.

# Instructions:
# 1. Go to GitLab > Settings > CI/CD > Variables, set AUTHOR_WHITELIST to a comma-separated list of allowed emails, such as "abc1@yourcompany.com,abc2@yourcompany.com,abc3@yourcompany.com".
# 2. Add this script as a job in your gitlab yaml file.


# 1. Validate input
if [[ -z "${AUTHOR_WHITELIST:-}" ]]; then
  echo "❌ AUTHOR_WHITELIST is not defined. Please set it in GitLab CI/CD variables."
  exit 1
fi

# Split whitelist into array
IFS=',' read -r -a WHITELIST <<< "$AUTHOR_WHITELIST"

# 2. Get latest commit author info
COMMIT_EMAIL=$(git log -1 --pretty=format:'%ae')
COMMIT_NAME=$(git log -1 --pretty=format:'%an')

echo "Checking latest commit author: $COMMIT_NAME <$COMMIT_EMAIL>"

# 3. Check against whitelist
is_whitelisted=false
for allowed in "${WHITELIST[@]}"; do
  if [[ "$COMMIT_EMAIL" == "$allowed" ]]; then
    is_whitelisted=true
    break
  fi
done

# 4. Decide result
if [[ "$is_whitelisted" == true ]]; then
  echo "✅ Commit author is whitelisted."
else
  echo "❌ Commit author NOT in whitelist."
  echo "   Please amend your commit locally, for example:"
  echo "     git commit --amend --author=\"Bot <bot@yourcompany.com>\""
  echo "   and force-push again."
  exit 1
fi
