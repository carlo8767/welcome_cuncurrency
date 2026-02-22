import React, { useState } from 'react';

const FileUploader = ({ onUploadSuccess }) => {
  const [file, setFile] = useState(null);
  const [preview, setPreview] = useState(null);
  const [loading, setLoading] = useState(false);

  // Handle file selection and preview
  const handleFileChange = (e) => {
    const selected = e.target.files[0];
    setFile(selected);
    if (selected) {
      setPreview(URL.createObjectURL(selected));
    }
  };

  const uploadToAPI = async () => {
    if (!file) return;
    setLoading(true);

    const formData = new FormData();
    formData.append('image', file);

    try {
      const response = await fetch('http://localhost:5000/upload', {
        method: 'POST',
        body: formData,
      });
      const data = await response.json();
      onUploadSuccess(data); // Pass results back to parent App
    } catch (err) {
      console.error("Upload failed", err);
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="uploader-card" style={{ border: '2px dashed #ccc', padding: '20px', borderRadius: '10px' }}>
      <h3>1. Select Image</h3>
      <input type="file" onChange={handleFileChange} accept="image/*" />
      
      {preview && (
        <div style={{ marginTop: '20px' }}>
          <img src={preview} alt="Preview" style={{ maxWidth: '100%', height: 'auto', borderRadius: '5px' }} />
        </div>
      )}

      <button 
        onClick={uploadToAPI} 
        disabled={!file || loading}
        style={{ marginTop: '20px', backgroundColor: loading ? '#666' : '#ff4400', color: 'white', padding: '10px 20px', border: 'none', cursor: 'pointer' }}
      >
        {loading ? "Analyzing..." : "Run Fire Detection"}
      </button>
    </div>
  );
};

export default FileUploader;