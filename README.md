# weball

**A brutally simple, end-to-end encrypted chat. No backend. No logs. No bullshit.**

Two browsers → one shared link → messages encrypted in the browser → only you and the other person can read them.  
If the page is closed or refreshed, the conversation is gone forever.

### Why this exists
- Existing “secure” messengers still phone home, keep metadata, or require accounts.  
- The EU (and others) keep proving they cannot be trusted with backdoors.  
- I wanted a toy that teaches me low-level C, WebRTC, and crypto while producing something actually private.

So I built the chat equivalent of a burn-after-reading note … except it’s written in C, compiled to WebAssembly, and runs entirely in your browser.

### Features (that actually matter)
- End-to-end encryption (X25519 + AES-256-GCM + HKDF-SHA512)  
- "Disposable" OpenVPN tunnel between peers
- No server side code whatsoever (static files only)  
- No accounts, no phone numbers, no metadata  
- Perfect forward secrecy on every new session  
- Messages self-destruct when the tab closes  
- Works offline (P2P via WebRTC DataChannels)  
- < 80 KB total download (gzipped)

### Try it
https://your-domain.example/weball/

Click “Create room” → send the link → start typing. That’s it.

### Building from source
```bash
git clone https://github.com/H4-sudo/weball.git
cd weball
make          # builds weball.wasm + index.html
make serve    # local test server on :8000