<h2 id="problem-to-solve">Problem to Solve</h2>

<p>In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a <em>key</em>: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called <em>ciphertext</em>) back into the original message (generally called <em>plaintext</em>).</p>

<p>A key, for example, might be the string <code class="language-plaintext highlighter-rouge">NQXPOMAFTRHLZGECYJIUWSKDVB</code>. This 26-character key means that <code class="language-plaintext highlighter-rouge">A</code> (the first letter of the alphabet) should be converted into <code class="language-plaintext highlighter-rouge">N</code> (the first character of the key), <code class="language-plaintext highlighter-rouge">B</code> (the second letter of the alphabet) should be converted into <code class="language-plaintext highlighter-rouge">Q</code> (the second character of the key), and so forth.</p>

<p>A message like <code class="language-plaintext highlighter-rouge">HELLO</code>, then, would be encrypted as <code class="language-plaintext highlighter-rouge">FOLLE</code>, replacing each of the letters according to the mapping determined by the key.</p>

<p>In a file called <code class="language-plaintext highlighter-rouge">substitution.c</code> in a folder called <code class="language-plaintext highlighter-rouge">substitution</code>, create a program that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.</p>

<h2 id="specification">Specification</h2>

<p>Design and implement a program, <code class="language-plaintext highlighter-rouge">substitution</code>, that encrypts messages using a substitution cipher.</p>

<ul>
  <li data-marker="*">Implement your program in a file called <code class="language-plaintext highlighter-rouge">substitution.c</code> in a directory called <code class="language-plaintext highlighter-rouge">substitution</code>.</li>
  <li data-marker="*">Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.</li>
  <li data-marker="*">If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with <code class="language-plaintext highlighter-rouge">printf</code>) and return from <code class="language-plaintext highlighter-rouge">main</code> a value of <code class="language-plaintext highlighter-rouge">1</code> (which tends to signify an error) immediately.</li>
  <li data-marker="*">If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with <code class="language-plaintext highlighter-rouge">printf</code>) and return from <code class="language-plaintext highlighter-rouge">main</code> a value of <code class="language-plaintext highlighter-rouge">1</code> immediately.</li>
  <li data-marker="*">Your program must output <code class="language-plaintext highlighter-rouge">plaintext:</code> (without a newline) and then prompt the user for a <code class="language-plaintext highlighter-rouge">string</code> of plaintext (using <code class="language-plaintext highlighter-rouge">get_string</code>).</li>
  <li data-marker="*">Your program must output <code class="language-plaintext highlighter-rouge">ciphertext:</code> (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.</li>
  <li data-marker="*">Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.</li>
  <li data-marker="*">After outputting ciphertext, you should print a newline. Your program should then exit by returning <code class="language-plaintext highlighter-rouge">0</code> from <code class="language-plaintext highlighter-rouge">main</code>.</li>
</ul>

<p>You might find one or more functions declared in <code class="language-plaintext highlighter-rouge">ctype.h</code> to be helpful, per <a href="https://manual.cs50.io/">manual.cs50.io</a>.</p>

<h2 id="how-to-test">How to Test</h2>

<h3 id="correctness">Correctness</h3>

<p>In your terminal, execute the below to check your work’s correctness.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>check50 cs50/problems/2024/x/substitution
</code></pre></div></div>

<details><summary>How to Use <code>debug50</code></summary><p>Looking to run <code class="language-plaintext highlighter-rouge">debug50</code>? You can do so as follows, after compiling your code successfully with <code class="language-plaintext highlighter-rouge">make</code>,</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>debug50 ./substitution KEY
</code></pre></div></div>

<p>wherein <code class="language-plaintext highlighter-rouge">KEY</code> is the key you give as a command-line argument to your program. Note that running</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>debug50 ./substitution
</code></pre></div></div>

<p>will (ideally!) cause your program end by prompting the user for a key.</p></details>

<h3 id="style">Style</h3>

<p>Execute the below to evaluate the style of your code using <code class="language-plaintext highlighter-rouge">style50</code>.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>style50 substitution.c
</code></pre></div></div>

<h2 id="how-to-submit">How to Submit</h2>

<p>In your terminal, execute the below to submit your work.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>submit50 cs50/problems/2024/x/substitution
</code></pre></div></div>
</body></html>