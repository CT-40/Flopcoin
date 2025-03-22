# 🪙 Flopcoin Core v1.3.0.0 Release Notes  
### **March 2025**

## **Overview**

Flopcoin v1.3.0.0 is a **comprehensive consensus and infrastructure upgrade** that introduces merged mining support (AuxPoW), a new difficulty adjustment system, multiple dynamic RPC improvements, and enhanced soft fork handling logic. Inspired by Dogecoin’s improvements (v1.14.2 to v1.14.9), this release also includes **security-focused version bit lockdown**, **dynamic fork tracking**, and **custom feature logic built into the consensus layer**.

This release is the result of a deep modernization process and **custom fork evolution**, and includes contributions from Dogecoin and Flopcoin developers.

---

## 🔐 **Consensus Changes & Protocol Hardening**

### ✅ Version Bits Security Overhaul  
- Only version bits **0 (CSV)** and **1 (SegWit)** are kept enabled (bit 2 reserved).  
- **All others (bits 3–28) are explicitly disabled** using `ThresholdState::NEVER_ACTIVE`.  
- **Rationale:** Prevent accidental activation or manipulation of undefined BIPs.

### ✅ Soft Fork Activation Tracking (Dynamic)  
- We created a dynamic system to **detect soft fork status** using live blockchain data.
- **`getversionbitsinfo` RPC** dynamically checks and reports the state of:
  - Version bits 0–28  
  - BIP34, BIP65, and BIP66 (legacy soft forks)  
- Soft fork states: `DEFINED`, `STARTED`, `LOCKED_IN`, `ACTIVE`, or `FAILED`

---

## ⛏️ **Difficulty Adjustment System Revamped**

### 🔁 New Algorithm Activation (Block 111,000 – `V3ForkHeight`)
- Switched to a **Digishield-inspired difficulty retargeting** algorithm.
- Replaces legacy code that allowed minimum difficulty resets.
- **Key logic updated in `flopcoin.cpp` and `pow.cpp`**:
  - Uses time modulation to control actual timespan variance
  - Enforces tighter bounds on difficulty jumps

### ❌ Minimum Difficulty Block Logic Disabled
- `fPowAllowMinDifficultyBlocks = false`  
- `AllowMinDifficultyForBlock` and `AllowDigishieldMinDifficultyForBlock` logic remains for testnet only

---

## 🚀 **Auxiliary Proof-of-Work (AuxPoW)**

### 🔓 Activated at Block 110,000
- Enables merged mining with other SHA256 coins
- Includes `CheckAuxPowProofOfWork` logic and strict `nAuxpowChainId` validation

### 🔎 Custom RPC Integration
We created a new, smart RPC command that checks both:
1. If AUXPOW is activated by height
2. If **any** AUXPOW block has been mined  
→ Using backward block scan with `IsAuxpow()`  
Command:  
```bash
flopcoin-cli isauxpowenabled
```
Returns:
```json
{
  "activated": true,
  "has_mined_block": true
}
```

---

## 🛰️ **New RPC Commands**

1. ### 📘 `getversionbitsinfo`
   - Lists all version bits and their status (`ACTIVE`, `LOCKED_IN`, etc.)
   - Includes dynamic checks for BIP34, BIP65, BIP66 soft forks

2. ### ⚙️ `getdifficultyalgo`
   - Shows the currently active difficulty algorithm:
     - `"Original"` or `"Digishield"`

3. ### 🔐 `isauxpowenabled`
   - Reports both activation status and whether **AUXPOW blocks** are present

---

## 🧠 **Adopted from Dogecoin Core (v1.14.2 → v1.14.9)**

Key improvements cherry-picked and adapted:
- Fee policy improvements (min fee logic, dust reduction)
- Faster validation paths and sync improvements
- Security patches for message parsing and mempool handling
- Preparation groundwork for `createauxblock`, `submitauxblock` (future-compatible)
- Cleaner logging, more efficient relay logic, and RPC validation

> These changes helped modernize Flopcoin while preserving its lightweight structure.

---

## 🧱 **Checkpoints**

- New static checkpoints added to the codebase to improve:
  - Sync performance
  - Chain security
  - Reorg resistance

---

## ⚙️ **Developer Notes**

**Consensus Constants:**
```cpp
consensus.AUXPOWHeight = 110000;
consensus.V3ForkHeight = 111000;
```

These heights are now referenced dynamically throughout consensus logic, so future forks are easier to manage.

---

## 📢 **Upgrade Required**

This is a **mandatory release** due to soft fork changes. Upgrade **before block 110,000** to avoid forking off the main chain.

**Upgrade Steps:**
1. Backup your wallet (`wallet.dat`)
2. Stop your node:
   ```bash
   flopcoin-cli stop
   ```
3. Replace binaries and restart the node.
4. Use the new RPCs to verify:
   ```bash
   flopcoin-cli getdifficultyalgo
   flopcoin-cli getversionbitsinfo
   flopcoin-cli isauxpowenabled
   ```

---

## ✅ Final Notes

Flopcoin v1.3.0.0 is the most important upgrade to date. It redefines mining rules, locks down security boundaries, and introduces a toolkit of developer and operator-friendly RPCs to future-proof the chain.

We strongly recommend all nodes, wallets, and pools **upgrade immediately** to stay on the longest valid chain.




