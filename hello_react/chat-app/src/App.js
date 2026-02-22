import React from "react";
// Use relative paths (assuming they are in the same src/component folder)
import Chat from "./component/Chat";
import FileUploader from "./component/FileUploader";

function App() {
  return (
    <div className="App" style={{ padding: '20px' }}>
      <h1>Robotics Control Center</h1>
      
      {/* 1. The Chat Interface */}
      <section style={{ marginBottom: '40px' }}>
        <Chat />
      </section>

      <hr />

      {/* 2. The Fire/Obstacle Uploader */}
      <section style={{ marginTop: '40px' }}>
        <h2>Image Detection</h2>
        <FileUploader />
      </section>
    </div>
  );
}

export default App;