//Get the link to the previous page
var previousUrl = document.referrer;

// Check if document.referrer is available
if (previousUrl) {
    // Check if the previous page and the current one are in the same domain
    if (new URL(previousUrl).origin === window.location.origin) {
      fetch(previousUrl)
        .then((response) => response.text())
        // Get the title of the previous page
        .then((html) => {
          const parser = new DOMParser();
          const doc = parser.parseFromString(html, "text/html");
          const pageTitle = doc.title.split(' - ')[0];

          // Get the target of the previous page
          var matches = previousUrl.match(/esp32[0-9a-z]*/);
          if (matches && matches.length) {
            var previousTarget = matches[0];
          }

          // Get the target of the current page
          var currentUrl = window.location.href;
          matches = currentUrl.match(/esp32[0-9a-z]*/);
          if (matches && matches.length) {
            var currentTarget = matches[0];
          }

          // Check if the target of the previous page and the current page are the same
          if (previousTarget != currentTarget) {

            // Convert the target into uppercase
            var uppercaseTarget = currentTarget.replace(/esp32([a-z]+)/, function(_, p1) {
              return "ESP32-" + p1.toUpperCase();
            }).toUpperCase();

            // Print the message
            const isChinese = currentUrl.includes("zh");

            if (isChinese){
              var message = `${uppercaseTarget} 未包含 ${pageTitle} 页面，可能是由于该项测试不适用 ${uppercaseTarget}。`;
            } else {
              var message = `The page ${pageTitle} is not available for ${uppercaseTarget}, most likely because ${uppercaseTarget} does not support this test.`;
            }
            message_box.innerText = message;
          }
        })
        .catch((error) => {
          console.error("Error:", error);
        });
    } else {
      console.error("Referrer URL is from a different domain.");
    }
  } else {
    console.error("No referrer URL available.");
  }
